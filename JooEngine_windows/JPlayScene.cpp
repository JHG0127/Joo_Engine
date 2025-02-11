#include "JPlayScene.h"
#include "JGameObject.h"
#include "JPlayer.h"
#include "JTransform.h"
#include "JSpriteRenderer.h"

namespace joo
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		{
			Player* p1 = new Player();

			Transform* tr = p1->AddComponent<Transform>();

			tr->SetPos(800, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr = p1->AddComponent<SpriteRenderer>();

			sr->SetName(L"SR");

			AddGameObject(p1);
		}

		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPos(300, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPos(100, 650);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}
		
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}