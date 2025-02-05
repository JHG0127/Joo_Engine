#include "JApplication.h"
#include "Jinput.h"


namespace joo
{
	Application::Application()
		:mHwnd(nullptr),
		mHdc(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		/*mPlayer.SetPosition(0, 0);
		mPlayer2.SetPosition(0, 0);*/

		input::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		input::Update();
		mPlayer.Update();
		mPlayer2.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
		mPlayer2.Render(mHdc);
	}
}