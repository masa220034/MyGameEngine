#include "Model.h"

int Model::Load(std::string fileName)
{
	/*�ǂ�ł���
	* modelList�ɂԂ�����
	*���ǂ񂾃��f���̔ԍ���Ԃ�!
	*/
	ModelData* pData;
	pData = new ModelData;
	pData->filename_ = fileName;
	pData->pFbx_ = nullptr;

	//�t�@�C���l�[����������������A�ǂ܂�!
	for (auto& e : modelList)
	{
		if (e->filename_ == fileName)
		{
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
	//���f���ԍ��́AmodelList�̃C���f�b�N�X
	modelList[hModel]->transform_ = transform;
}

void Model::Draw(int hModel)
{
	//���f���ԍ��́AmodelList�̃C���f�b�N�X
	modelList[hModel]->pFbx_->Draw(modelList[hModel]->transform_);
}
