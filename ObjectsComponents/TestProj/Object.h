#pragma once
#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
	Object();

	~Object();

	virtual void Start();

	virtual void Update();

	template<typename T>
	T* GetPart()
	{
		return PartManager::GetInstance().GetPart<T>(mID);
	}

	template<typename T>
	void AddPart()
	{
		PartManager::GetInstance().AddPart<T>(mID);
	}

private:
	int mID;
};

#endif OBJECT_H
