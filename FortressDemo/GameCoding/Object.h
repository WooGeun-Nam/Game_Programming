#pragma once

enum class ObjectType
{
	None,
	Player,
	Monster,
	Projectile
};

class Object
{
public:
	Object(ObjectType type);
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

public:
	ObjectType GetObjectType() { return _type; }

	Vector GetPos() { return _pos; }
	void SetPos(Vector pos) { _pos = pos; };

	float GetRadius() { return _radius; }
	void SetRadius(float radius) { _radius = radius; }
protected:
	ObjectType _type = ObjectType::None;
	Stat _stat = {};
	Vector _pos = {};
	Dir _dir = Dir::Left;
	float _radius = 50.f;
};

