//#include <iostream>
#include "Engine.h"
#include "MemoryManagement/VenisMemoryBuffer.h"


VenisBufferManager* VenisBufferManager::Instance = NULL;
int VenisEngine::VenisEngineMain()
{
	std::cout << "RunningEngine" << std::endl;
	VenisBufferManager::GetInstance();
	VenisBufferManager::GetInstance()->CreateBuffer<Temporary>(100);

	Temporary* temp  = new Temporary;
	std::cout << temp->justAValue << std::endl;
	std::cin;
	VenisBufferManager::DestroyInstance();
	return 0;
}