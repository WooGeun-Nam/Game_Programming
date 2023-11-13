#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "LineMesh.h"

Player::Player() : Object(ObjectType::Player)
{
}

Player::~Player()
{
}

void Player::Init()
{
	// 데이터시트(고정값) : Excel, Json
	// 데이터베이스 : Oracle, MSSQL
	// 데이터시트 != 데이터베이스
	// TODO : Data
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 500;

	_pos.x = 400;
	_pos.y = 500;
}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (_playerTurn == false)
		return;

	// 하드웨어 성능 차이에 따른 속도 차이를 시간으로 계산
	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= _stat.speed * deltaTime;
		_dir = Dir::Left;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_pos.x += _stat.speed * deltaTime;
		_dir = Dir::Right;
	}

	// 대각선으로 움직이면 빨라진다
	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		//_pos.y -= _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		//_pos.y += _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		// TODO : 미사일 발사
	}
}

void Player::Render(HDC hdc)
{
	// Utils::DrawCircle(hdc, _pos, 50);

	if (_dir == Dir::Left)
	{
		const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(GetMeshKey());
		if (mesh)
			mesh->Render(hdc, _pos, 0.5f, 0.5f);
		// 음수의 경우 반전 mesh->Render(hdc, _pos, -0.5f, 0.5f);
	}
	else
	{
		const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(GetMeshKey());
		if (mesh)
			mesh->Render(hdc, _pos, -0.5f, 0.5f);
	}
	
	HPEN pen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)::SelectObject(hdc, pen);

	::SelectObject(hdc, oldPen);
	::DeleteObject(pen);
}

wstring Player::GetMeshKey()
{
	if (_playerType == PlayerType::MissileTank)
		return L"MissileTank";

	return L"CanonTank";
}
