#include "JApplication.h"
#include "Jinput.h"
#include "JTime.h"


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
		Time::Initialize();
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
		Time::Update();
		mPlayer.Update();
		mPlayer2.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Time::Render(mHdc);
		mPlayer.Render(mHdc);
		mPlayer2.Render(mHdc);
	}
}