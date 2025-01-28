#include "JGameObject.h"

namespace joo
{
	GameObject::GameObject()
		:mY(0),
		mX(0)
	{

	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
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