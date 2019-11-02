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

	template <typename T>
	T* GetPart();

	template<typename T>
	void AddPart();

private:
	int mID;
};

#endif OBJECT_H
