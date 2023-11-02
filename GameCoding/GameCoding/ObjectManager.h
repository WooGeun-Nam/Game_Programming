#pragma once

class Object;

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);

	~ObjectManager();

	void Add(Object* object);
	void Remove(Object* object);
	void Clear();
	
	// ���� : ������ ����
	// �浹�� ��� �ٸ� ������ ��ġ�� �˾ƾ� �Ѵ�
	const vector<Object*>& GetObjects() { return _objects; }

	// C++ ���� Template�� �ڵ� �߷�
	template<typename T>
	T* CreateObject()
	{
		// type trait
		// Object Ÿ�� �̾�� �Ѿ �� �̴�.
		static_assert(std::is_convertible_v<T*, Object*>);

		T* object = new T();
		object->Init();

		return object;
	}

private:
	vector<Object*> _objects;
};
