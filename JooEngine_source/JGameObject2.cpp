#include "JGameObject2.h"
#include "Jinput.h"
#include "JTime.h"

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
		const int speed = 50.0f;
		if (input::GetKey(eKeyCode::Left) || input::GetKey(eKeyCode::LB))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (input::GetKey(eKeyCode::Right) || input::GetKey(eKeyCode::RB))
		{
			mX += speed * Time::DeltaTime();
		}

		if (input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
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