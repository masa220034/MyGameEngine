#include "Model.h"

int Model::Load(std::string fileName)
{
	/*読んでつくる
	* modelListにぶち込む
	*今読んだモデルの番号を返す!
	*/
	ModelData* pData;
	pData = new ModelData;
	pData->filename_ = fileName;
	pData->pFbx_ = nullptr;

	//ファイルネームが同じだったら、読まん!
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
	//モデル番号は、modelListのインデックス
	modelList[hModel]->transform_ = transform;
}

void Model::Draw(int hModel)
{
	//モデル番号は、modelListのインデックス
	modelList[hModel]->pFbx_->Draw(modelList[hModel]->transform_);
}
