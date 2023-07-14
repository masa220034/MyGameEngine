#include "Dice.h"
#include "Camera.h"

Dice::Dice() :
	pVertexBuffer_(nullptr), pIndexBuffer_(nullptr), pConstantBuffer_(nullptr), pTexture_(nullptr)
{
}

Dice::~Dice()
{
	Release();
}

HRESULT Dice::Initialize()
{
	HRESULT hr;

	// ���_���
	VERTEX vertices[] =
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

	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(vertices);
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices;
	hr = Direct3D::pDevice_->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(nullptr, "���_�o�b�t�@�̍쐬�Ɏ��s���܂���", "�G���[", MB_OK);
		return hr;
	}

	//�C���f�b�N�X���
	int index[] = { 0,2,3, 0,1,2,        //�����`(�O)
					4,6,7, 4,5,6,        //�����`(��)
					8,10,11, 8,9,10,     //�����`(���)
					12,14,15, 12,13,14,  //�����`(��)
					16,18,19, 16,17,18,  //�����`(�E) 
					20,22,23, 20,21,22   //�����`(��)
	};

	// �C���f�b�N�X�o�b�t�@�𐶐�����
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(index);
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = index;
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	hr = Direct3D::pDevice_->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(nullptr, "�C���f�b�N�X�o�b�t�@�̍쐬�Ɏ��s���܂���", "�G���[", MB_OK);
		return hr;
	}

	//�R���X�^���g�o�b�t�@�쐬
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// �R���X�^���g�o�b�t�@�̍쐬
	hr = Direct3D::pDevice_->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	if (FAILED(hr))
	{
		MessageBox(nullptr, "�R���X�^���g�o�b�t�@�̍쐬�Ɏ��s���܂���", "�G���[", MB_OK);
		return hr;
	}

	pTexture_ = new Texture;
	pTexture_->Load("Assets\\Dice.png");

	return S_OK;
}

void Dice::Draw(XMMATRIX& worldMatrix)
{
	//�R���X�^���g�o�b�t�@�ɓn�����

	CONSTANT_BUFFER cb;
	cb.matWVP = XMMatrixTranspose(worldMatrix * Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
	cb.matW = XMMatrixTranspose(worldMatrix);

	D3D11_MAPPED_SUBRESOURCE pdata;
	Direct3D::pContext_->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));
	ID3D11SamplerState* pSampler = pTexture_->GetSampler();

	Direct3D::pContext_->PSSetSamplers(0, 1, &pSampler);
	ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
	Direct3D::pContext_->PSSetShaderResources(0, 1, &pSRV);	// �f�[�^��l�𑗂�
	Direct3D::pContext_->Unmap(pConstantBuffer_, 0);	//�ĊJ

	//���_�o�b�t�@
	UINT stride = sizeof(VERTEX);
	UINT offset = 0;
	Direct3D::pContext_->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);

	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
	stride = sizeof(int);
	offset = 0;
	Direct3D::pContext_->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);

	//�R���X�^���g�o�b�t�@
	Direct3D::pContext_->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
	Direct3D::pContext_->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p

	Direct3D::pContext_->DrawIndexed(36, 0, 0); //�O�p�`�ɕ��������Ƃ��̒��_�̍��v�̐�
}

void Dice::Release()
{
	SAFE_RELEASE(pConstantBuffer_);
	SAFE_RELEASE(pIndexBuffer_);
	SAFE_RELEASE(pVertexBuffer_);
	SAFE_RELEASE(pTexture_);
}