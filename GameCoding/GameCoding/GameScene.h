#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene() override;

	// 순수 가상 함수
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
};

