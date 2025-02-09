#include "JGameObject.h"
#include "Jinput.h"
#include "JTime.h"

namespace joo
{
	GameObject::GameObject()
		:mX(0),
		mY(0)
	{

	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
		}

		if (input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH bluebrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)); //파랑 브러쉬 생성
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, bluebrush); //파랑브러쉬 DC에 선택 그리고 흰색 브러쉬 반환

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

		(HBRUSH)SelectObject(hdc, oldbrush); //다시 흰색 브러쉬로 선택
		DeleteObject(bluebrush); //파랑브러쉬 삭제

		//(HPEN)SelectObject(mHdc, oldpen);
		DeleteObject(redPen);
	}
}