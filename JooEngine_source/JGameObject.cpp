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
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255)); //�Ķ� �귯�� ����
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, bluebrush); //�Ķ��귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldpen = (HPEN)SelectObject(mHdc, redPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		(HBRUSH)SelectObject(hdc, oldbrush); //�ٽ� ��� �귯���� ����
		DeleteObject(bluebrush); //�Ķ��귯�� ����

		//(HPEN)SelectObject(mHdc, oldpen);
		DeleteObject(redPen);
	}
}