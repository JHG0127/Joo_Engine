#pragma once
#include "Commoninclude.h"
#include "JGameObject.h"

namespace joo
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		//float mSpeed;

		//플레이어
		/*float mX;
		float mY;*/
		
		GameObject mPlayer;
		
	};
}

