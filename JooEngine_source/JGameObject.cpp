#include "JGameObject.h"
#include "Jinput.h"

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
		if (input::GetKey(eKeyCode::A))
		{
			mX -= 0.01;
		}

		if (input::GetKey(eKeyCode::D))
		{
			mX += 0.01;
		}

		if (input::GetKey(eKeyCode::W))
		{
			mY -= 0.01;
		}

		if (input::GetKey(eKeyCode::S))
		{
			mY += 0.01;
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255)); //파랑 브러쉬 생성
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, bluebrush); //파랑브러쉬 DC에 선택 그리고 흰색 브러쉬 반환

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldpen = (HPEN)SelectObject(mHdc, redPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		(HBRUSH)SelectObject(hdc, oldbrush); //다시 흰색 브러쉬로 선택
		DeleteObject(bluebrush); //파랑브러쉬 삭제

		//(HPEN)SelectObject(mHdc, oldpen);
		DeleteObject(redPen);
	}
}