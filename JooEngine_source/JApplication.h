#pragma once
#include "Commoninclude.h"
#include "JGameObject.h"
#include "JGameObject2.h"

namespace joo
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
		//float mSpeed;

		//플레이어
		/*float mX;
		float mY;*/
		
		GameObject mPlayer;
		GameObject2 mPlayer2;
		
	};
}

