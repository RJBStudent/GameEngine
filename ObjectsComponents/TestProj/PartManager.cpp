#include "PartManager.h"
#include <iostream>

PartManager::~PartManager()
{
	std::cout << "PartManager Destructor \n";
}

void PartManager::init()
{

}

void PartManager::CleanUp()
{
}

void PartManager::Update()
{
	std::cout << "PartManager Update \n";

	for (auto it = mOICMap.begin(); it != mOICMap.end(); it++)
	{
		it->second.Update();
	}
}

template <typename T>
T* PartManager::GetPart(int objectIndex)
{
	auto allParts = mOICMap.equal_range(objectIndex);
	for (auto it = allParts.first; it != allParts.second; it++)
	{
		if (typeid(it->second) == typeid(T))
		{
			return &it->second;
		}
	}

	return nullptr;
}

template <typename T>
void PartManager::AddPart(int objectIndex)
{
	mOICMap.insert({ objectIndex, T() });
}
