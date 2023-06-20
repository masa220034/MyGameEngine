#include "Dice.h"

void Dice::InitVertexData()
{
	// 頂点情報
	vertices_ =
	{
		{XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(前)の頂点（左上）
		{XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(前)の頂点（右上）
		{XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(前)の頂点（右下）
		{XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(前)の頂点（左下）

		{XMVectorSet(-1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(上)の頂点（左上）
		{XMVectorSet(1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(上)の頂点（右上）
		{XMVectorSet(1.0f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(上)の頂点（右下）
		{XMVectorSet(-1.0f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(上)の頂点（左下）

		{XMVectorSet(1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(後ろ)の頂点（右上）
		{XMVectorSet(-1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(後ろ)の頂点（左上）
		{XMVectorSet(-1.0f, -1.0f, 2.0f, 0.0f), XMVectorSet(0.5f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(後ろ)の頂点（左下）
		{XMVectorSet(1.0f, -1.0f, 2.0f, 0.0f), XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(後ろ)の頂点（右下）

		{XMVectorSet(1.0f,  -1.0f, 2.0f, 0.0f), XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(下)の頂点（右上）
		{XMVectorSet(-1.0f,  -1.0f, 2.0f, 0.0f), XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(下)の頂点（左上）
		{XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(下)の頂点（左下）
		{XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(下)の頂点（右下）

		{XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,0.0f, 0.0f) },	// 正方形(右)の頂点（左上）
		{XMVectorSet(1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,0.0f, 0.0f) },	// 正方形(右)の頂点（右上）
		{XMVectorSet(1.0f, -1.0f, 2.0f, 0.0f), XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,0.0f, 0.0f) },	// 正方形(右)の頂点（右下）
		{XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,0.0f, 0.0f) },	// 正方形(右)の頂点（左下）

		{XMVectorSet(-1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(左)の頂点（左上）
		{XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(左)の頂点（右上）
		{XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(左)の頂点（右下）
		{XMVectorSet(-1.0f, -1.0f, 2.0f, 0.0f), XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// 正方形(左)の頂点（左下）
	};

	vertexNum_ = vertices_.size();
}


void Dice::InitIndexData()
{
	index_ = { 0,1,2, 0,2,3, 4,5,6, 4,6,7, 8,9,10, 8,10,11, 12,13,14, 12,14,15, 16,17,18, 16,18,19, 20,21,22, 20,22,23, };

	//インデックス数
	indexNum_ = index_.size();
}
