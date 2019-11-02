#pragma once
#ifndef PARTMANAGER_H
#define PARTMANAGER_H
#include "Part.h"
#include <unordered_map>

//Singleton
class PartManager
{
public:
	static PartManager& GetInstance() { static PartManager instance; return instance; }

	PartManager(PartManager const&) = delete;
	void operator=(PartManager const&) = delete;

	void init();
	void CleanUp();

	void Update();
	template <typename T>
	T* GetPart(int objectIndex);
	template <typename T>
	void AddPart(int objectIndex);

private:
	PartManager() {}
	~PartManager();

	//Object Index to Component Map
	std::unordered_multimap<int, Part> mOICMap;
};

#endif PARTMANAGER_H