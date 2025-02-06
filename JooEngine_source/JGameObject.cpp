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