#pragma once
#ifndef PARTMANAGER_H
#define PARTMANAGER_H
#include <unordered_map>
#include <utility>
#include <type_traits>
#include <typeindex>
#include "TestPart.h"

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
	T* GetPart(int objectIndex)
	{
		auto allParts = mOICMap.equal_range(objectIndex);
		for (auto it = allParts.first; it != allParts.second; it++)
		{
			if (typeid(it->second) == typeid(T))
			{
				auto returner = it->second;                                                                                                                                                                                                                                                                              
				return dynamic_cast<T*>(returner);
			}
		}

		return nullptr;
	}

	template <typename T>
	void AddPart(int objectIndex)
	{
		T part;
		mOICMap.insert({ objectIndex, part });
	}

private:
	PartManager() {}
	~PartManager();

	//Object Index to Component Map
	std::unordered_multimap<int, Part> mOICMap;
};

#endif PARTMANAGER_H