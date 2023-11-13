#pragma once
#include "Object.h"

enum class PlayerType
{
	CanonTank,
	MissileTank
};

class Player : public Object
{
public:
	Player();
	virtual ~Player() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	wstring GetMeshKey();

	void SetPlayerType(PlayerType playerType) { _playerType = playerType; }

public:
	PlayerType _playerType = PlayerType::CanonTank;
};

