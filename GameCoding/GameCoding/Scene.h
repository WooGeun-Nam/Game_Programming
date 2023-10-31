#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

	// 순수 가상 함수
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

protected:

};

