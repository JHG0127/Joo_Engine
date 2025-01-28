#include "JApplication.h"

namespace joo
{
	Application::Application()
		:mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0.0),
		mX(0.0),
		mY(0.0)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		mSpeed += 0.01;

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01;
		}
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255)); //�Ķ� �귯�� ����
		HBRUSH oldbrush = (HBRUSH)SelectObject(mHdc, bluebrush); //�Ķ��귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldpen = (HPEN)SelectObject(mHdc, redPen);

		Rectangle(mHdc, 100+mX, 100+mY, 200+mX, 200+mY);

		(HBRUSH)SelectObject(mHdc, oldbrush); //�ٽ� ��� �귯���� ����
		DeleteObject(bluebrush); //�Ķ��귯�� ����

		//(HPEN)SelectObject(mHdc, oldpen);
		DeleteObject(redPen);
	}
}