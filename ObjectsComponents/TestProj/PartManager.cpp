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
