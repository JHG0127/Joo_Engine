#include "JGameObject2.h"

namespace joo {
	GameObject2::GameObject2()
		:mX(0),
		mY(0)
	{

	}

	GameObject2::~GameObject2()
	{

	}

	void GameObject2::Update()
	{
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01;
		}

		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01;
		}

		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01;
		}

		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01;
		}
	}

	void GameObject2::LateUpdate()
	{

	}

	void GameObject2::Render(HDC hdc)
	{
		HBRUSH redbrush = CreateSolidBrush(RGB(255, 0, 0)); //�Ķ� �귯�� ����
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, redbrush); //�Ķ��귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldpen = (HPEN)SelectObject(mHdc, redPen);

		Ellipse(hdc, 600 + mX, 600 + mY,650 + mX, 650 + mY);

		(HBRUSH)SelectObject(hdc, oldbrush); //�ٽ� ��� �귯���� ����
		DeleteObject(redbrush); //�Ķ��귯�� ����

		//(HPEN)SelectObject(mHdc, oldpen);
		DeleteObject(redPen);
	}
}