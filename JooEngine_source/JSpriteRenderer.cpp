#include "JSpriteRenderer.h"
#include "JGameObject.h"
#include "JTransform.h"

joo::SpriteRenderer::SpriteRenderer()
{
}

joo::SpriteRenderer::~SpriteRenderer()
{
}

void joo::SpriteRenderer::Initialize()
{
}

void joo::SpriteRenderer::Update()
{
}

void joo::SpriteRenderer::LateUpdate()
{
}

void joo::SpriteRenderer::Render(HDC hdc)
{
	HBRUSH bluebrush = CreateSolidBrush(RGB(255, 0, 255)); //�Ķ� �귯�� ����
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, bluebrush); //�Ķ��귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
	SelectObject(hdc, oldPen);

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Rectangle(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());


	(HBRUSH)SelectObject(hdc, oldbrush); //�ٽ� ��� �귯���� ����
	DeleteObject(bluebrush); //�Ķ��귯�� ����
	DeleteObject(redPen);
}
