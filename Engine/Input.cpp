#include "Input.h"
#include <string>

namespace Input
{
	LPDIRECTINPUT8   pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
	BYTE keyState[256];        //現在の各キーの状態
	BYTE prevKeyState[256];    //前フレームでの各キーの状態

	//マウス
	LPDIRECTINPUTDEVICE8 pMouseDevice; //デバイスオブジェクト
	DIMOUSESTATE mouseState;           //マウスの状態
	DIMOUSESTATE prevMouseState;       //前フレームのマウスの状態
	XMFLOAT3 mousePosition;            //マウスカーソルの位置

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);

		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);                 //デバイスオブジェクトを作成
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);                                    //デバイスの種類(今回はキーボード)を指定
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);  //協調レベルの設定

		//マウス
		pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice, nullptr);                 //デバイスオブジェクトを作成
		pMouseDevice->SetDataFormat(&c_dfDIMouse);                                    //デバイスの種類(今回はマウス)を指定
		pMouseDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);  //協調レベルの設定

	}

	void Update()
	{
		memcpy(prevKeyState, keyState, sizeof(BYTE)*256);

		pKeyDevice->Acquire();
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState); 

		//マウス
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
		//今は押してて、前回は押してない
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
		//押してる
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