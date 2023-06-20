#include "Dice.h"

void Dice::InitVertexData()
{
	// ���_���
	vertices_ =
	{
		{XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(�O)�̒��_�i����j
		{XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(�O)�̒��_�i�E��j
		{XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(�O)�̒��_�i�E���j
		{XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(�O)�̒��_�i�����j

		{XMVectorSet(-1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.0f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i����j
		{XMVectorSet(1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i�E��j
		{XMVectorSet(1.0f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i�E���j
		{XMVectorSet(-1.0f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i�����j

		{XMVectorSet(1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(���)�̒��_�i�E��j
		{XMVectorSet(-1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(���)�̒��_�i����j
		{XMVectorSet(-1.0f, -1.0f, 2.0f, 0.0f), XMVectorSet(0.5f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(���)�̒��_�i�����j
		{XMVectorSet(1.0f, -1.0f, 2.0f, 0.0f), XMVectorSet(0.25f, 1.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(���)�̒��_�i�E���j

		{XMVectorSet(1.0f,  -1.0f, 2.0f, 0.0f), XMVectorSet(0.25f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i�E��j
		{XMVectorSet(-1.0f,  -1.0f, 2.0f, 0.0f), XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i����j
		{XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i�����j
		{XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.25f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i�E���j

		{XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,0.0f, 0.0f) },	// �����`(�E)�̒��_�i����j
		{XMVectorSet(1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,0.0f, 0.0f) },	// �����`(�E)�̒��_�i�E��j
		{XMVectorSet(1.0f, -1.0f, 2.0f, 0.0f), XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,0.0f, 0.0f) },	// �����`(�E)�̒��_�i�E���j
		{XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(1.0f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,0.0f, 0.0f) },	// �����`(�E)�̒��_�i�����j

		{XMVectorSet(-1.0f,  1.0f, 2.0f, 0.0f), XMVectorSet(0.75f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i����j
		{XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.5f, 0.0f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i�E��j
		{XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.5f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i�E���j
		{XMVectorSet(-1.0f, -1.0f, 2.0f, 0.0f), XMVectorSet(0.75f, 0.5f, 0.0f, 0.0f), XMVectorSet(0.0f,0.0f,1.0f, 0.0f) },	// �����`(��)�̒��_�i�����j
	};

	vertexNum_ = vertices_.size();
}


void Dice::InitIndexData()
{
	index_ = { 0,1,2, 0,2,3, 4,5,6, 4,6,7, 8,9,10, 8,10,11, 12,13,14, 12,14,15, 16,17,18, 16,18,19, 20,21,22, 20,22,23, };

	//�C���f�b�N�X��
	indexNum_ = index_.size();
}
