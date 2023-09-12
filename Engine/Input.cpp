#include "Input.h"
#include <string>

namespace Input
{
	LPDIRECTINPUT8   pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
	BYTE keyState[256];        //���݂̊e�L�[�̏��
	BYTE prevKeyState[256];    //�O�t���[���ł̊e�L�[�̏��

	//�}�E�X
	LPDIRECTINPUTDEVICE8 pMouseDevice; //�f�o�C�X�I�u�W�F�N�g
	DIMOUSESTATE mouseState;           //�}�E�X�̏��
	DIMOUSESTATE prevMouseState;       //�O�t���[���̃}�E�X�̏��
	XMFLOAT3 mousePosition;            //�}�E�X�J�[�\���̈ʒu

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);

		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);                 //�f�o�C�X�I�u�W�F�N�g���쐬
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);                                    //�f�o�C�X�̎��(����̓L�[�{�[�h)���w��
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);  //�������x���̐ݒ�

		//�}�E�X
		pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice, nullptr);                 //�f�o�C�X�I�u�W�F�N�g���쐬
		pMouseDevice->SetDataFormat(&c_dfDIMouse);                                    //�f�o�C�X�̎��(����̓}�E�X)���w��
		pMouseDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);  //�������x���̐ݒ�

	}

	void Update()
	{
		memcpy(prevKeyState, keyState, sizeof(BYTE)*256);

		pKeyDevice->Acquire();
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState); 

		//�}�E�X
		pMouseDevice->Acquire();
		memcpy(&prevMouseState, &mouseState, sizeof(mouseState));
		pMouseDevice->GetDeviceState(sizeof(mouseState), &mouseState);
	}

	bool IsKey(int keyCode)
	{
		if (keyState[keyCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	bool IsKeyDown(int keyCode)
	{
		//���͉����ĂāA�O��͉����ĂȂ�
		if (IsKey(keyCode) && !(prevKeyState[keyCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	bool IsKeyUp(int keyCode)
	{
		if (!IsKey(keyCode) && prevKeyState[keyCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	void Release()
	{
		SAFE_RELEASE(pDInput);
		SAFE_RELEASE(pKeyDevice);
	}

	bool IsMouseButton(int buttonCode)
	{
		//�����Ă�
		if (mouseState.rgbButtons[buttonCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	bool IsMouseButtonDown(int buttonCode)
	{
		if (IsMouseButton(buttonCode) && !(prevMouseState.rgbButtons[buttonCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	bool IsMouseButtonUp(int buttonCode)
	{
		if (!IsMouseButton(buttonCode) && prevMouseState.rgbButtons[buttonCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	XMFLOAT3 GetMousePosition()
	{
		return mousePosition;
	}

	XMFLOAT3 GetMouseMove()
	{
		XMFLOAT3 result = XMFLOAT3((float)mouseState.lX, 
			                       (float)mouseState.lY, 
			                       (float)mouseState.lZ);
		return result;
	}

	void SetMousePosition(int x, int y)
	{
		mousePosition.x = x;
		mousePosition.y = y;
		std::string resStr = std::to_string(x) + ", " + std::to_string(y);
		OutputDebugString(resStr.c_str());
	}
}