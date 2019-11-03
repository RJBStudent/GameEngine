//#include <iostream>
#include "Engine.h"
#include "MemoryManagement/VenisMemoryBuffer.h"

int VenisEngine::VenisEngineMain()
{
	std::cout << "RunningEngine" << std::endl;
		
	VenisBuffer::GetInstance()->NewBuffer(sizeof(Temporary));
	Temporary temp;
	//temp.justAValue
	VenisBuffer::cleanInstance();
	return 0;
}