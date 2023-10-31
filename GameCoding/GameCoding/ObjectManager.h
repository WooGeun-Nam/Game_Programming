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
	
	const vector<Object*>& GetObjects() { return _objects; }

	// C++ 에서 Template는 자동 추론
	template<typename T>
	T* CreateObject()
	{
		// type trait
		// Object 타입 이어야 넘어갈 것 이다.
		static_assert(std::is_convertible_v<T*, Object*>);

		T* object = new T();
		object->Init();

		return object;
	}

private:
	vector<Object*> _objects;
};

