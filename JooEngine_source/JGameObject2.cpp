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
		HBRUSH redbrush = CreateSolidBrush(RGB(255, 0, 0)); //파랑 브러쉬 생성
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, redbrush); //파랑브러쉬 DC에 선택 그리고 흰색 브러쉬 반환

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldpen = (HPEN)SelectObject(mHdc, redPen);

		Ellipse(hdc, 600 + mX, 600 + mY,650 + mX, 650 + mY);

		(HBRUSH)SelectObject(hdc, oldbrush); //다시 흰색 브러쉬로 선택
		DeleteObject(redbrush); //파랑브러쉬 삭제

		//(HPEN)SelectObject(mHdc, oldpen);
		DeleteObject(redPen);
	}
}