//#include <iostream>
#include "Engine.h"
#include "MemoryManagement/VenisMemoryBuffer.h"

int VenisEngine::VenisEngineMain()
{
	std::cout << "RunningEngine" << std::endl;
		
	//VenisBuffer::GetInstance()->NewBuffer(sizeof(Temporary));
	std::unique_ptr<Temporary> temp = std::make_unique<Temporary>();
	std::cout << temp->justAValue << std::endl;
	//VenisBuffer::cleanInstance();
	return 0;
}