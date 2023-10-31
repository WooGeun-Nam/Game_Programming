#include "pch.h"
#include "ObjectManager.h"
#include "Object.h"

ObjectManager::~ObjectManager()
{
	Clear();
}

void ObjectManager::Add(Object* object)
{
	if (object == nullptr)
		return;

	auto findit = std::find(_objects.begin(), _objects.end(), object);
	if (findit != _objects.end())
		return;

	_objects.push_back(object);
}

void ObjectManager::Remove(Object* object)
{
	if (object == nullptr)
		return;

	// [][][][][] 문제점 : 위치만 바꿔서 뒤로 보낸다
	auto it = std::remove(_objects.begin(), _objects.end(), object);
	_objects.erase(it, _objects.end());

	// TODO : 괜찮을까?
	delete object;
}

void ObjectManager::Clear()
{
	std::for_each(_objects.begin(), _objects.end(), [=](Object* obj) {delete obj; });
	
	_objects.clear();
}
