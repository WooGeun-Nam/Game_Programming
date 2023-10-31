#include "pch.h"
#include "DevScene.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
}

void DevScene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	// 하드웨어 성능 차이에 따른 속도 차이를 시간으로 계산
	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_playerPos.x -= _speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_playerPos.x += _speed * deltaTime;
	}
	
	// 대각선으로 움직이면 빨라진다
	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_playerPos.y -= _speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_playerPos.y += _speed * deltaTime;
	}
}

void DevScene::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _playerPos, 50);
}
