#include "Model.h"
#include "Direct3D.h"

namespace Model {

	//���f���̃|�C���^���Ԃ�����ł����x�N�^
	std::vector<ModelData*> modelList;
}

int Model::Load(std::string fileName)
{
	ModelData* pData;
	pData = new ModelData;
	pData->filename_ = fileName;
	pData->pFbx_ = nullptr;

	//�t�@�C���l�[����������������A�ǂ܂�I
	for (auto& e : modelList)
	{
		if (e->filename_ == fileName) {
			pData->pFbx_ = e->pFbx_;
			break;
		}
	}

	if (pData->pFbx_ == nullptr)
	{
		pData->pFbx_ = new Fbx;
		pData->pFbx_->Load(fileName);
	}

	modelList.push_back(pData);
	return(modelList.size() - 1);
}

void Model::SetTransform(int hModel, Transform transform)
{
	modelList[hModel]->transform_ = transform;
	//���f���ԍ��́AmodelList�̃C���f�b�N�X
}
void Model::Draw(int hModel) {
	//���f���ԍ��́AmodelList�̃C���f�b�N�X
	modelList[hModel]->pFbx_->Draw(modelList[hModel]->transform_);
}

void Model::Release()
{
	bool isReffered = false; //�Q�Ƃ���Ă�H
	for (int i = 0; i < modelList.size(); i++)
	{
		for (int j = i + 1; j < modelList.size(); j++)
		{
			if (modelList[i]->pFbx_ == modelList[j]->pFbx_)
			{
				isReffered = true;
				break;
			}
		}
		if (isReffered == false)
		{
			SAFE_DELETE(modelList[i]->pFbx_);
		}
		SAFE_DELETE(modelList[i]);
	}
	modelList.clear();
}

void Model::RayCast(int hModel, RayCastData& rayData)
{
	//?���f����transfrom��calclation
	modelList[hModel]->transform_.Calclation();
	//�@���[���h�s��̋t�s��
	XMMATRIX wInv = XMMatrixInverse(nullptr, modelList[hModel]->transform_.GetWorldMatrix());
	//�A���C�̒ʉߓ_�����߂�(���f����Ԃł̗�̕����x�N�g�������߂�)
	XMVECTOR vpass{ rayData.start.x + rayData.dir.x,
					rayData.start.y + rayData.dir.y,
	                rayData.start.z + rayData.dir.z,
	                rayData.start.w + rayData.dir.w};
	//�BrayData.start�����f����Ԃɕϊ�(�@��������)
	XMVECTOR vstart = XMLoadFloat4(&rayData.start);
	vstart = XMVector3TransformCoord(vstart, wInv); //transformcoord��w�v�f�𖳎����Ă����
	//�C(�n�_��������x�N�g�������傢�L�΂�����)�ʉߓ_(�A)�ɇ@��������
	vpass = XMVector3TransformCoord(vpass, wInv);
	//�DrayData.dir���B����C�Ɍ������x�N�g���ɂ���(�����Z)
	vpass = vpass - vstart;
	XMStoreFloat4(&rayData.dir, vpass);

	//�w�肵�����f���ԍ���FBX�Ƀ��C�L���X�g
	modelList[hModel]->pFbx_->RayCast(rayData);
}
