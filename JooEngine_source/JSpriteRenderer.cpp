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
	HBRUSH bluebrush = CreateSolidBrush(RGB(255, 0, 255)); //파랑 브러쉬 생성
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, bluebrush); //파랑브러쉬 DC에 선택 그리고 흰색 브러쉬 반환

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
	SelectObject(hdc, oldPen);

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Rectangle(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());


	(HBRUSH)SelectObject(hdc, oldbrush); //다시 흰색 브러쉬로 선택
	DeleteObject(bluebrush); //파랑브러쉬 삭제
	DeleteObject(redPen);
}
