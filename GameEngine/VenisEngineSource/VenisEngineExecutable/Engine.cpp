//#include <iostream>
#include "Engine.h"
#include "MemoryManagement/VenisMemoryBuffer.h"

int VenisEngine::VenisEngineMain()
{
	//std::cout << "RunningEngine" << std::endl;
	Temporary* t = new Temporary();

	VenisBuffer temporaryBuffer;
	temporaryBuffer.NewBuffer(t, 100);

	return 0;
}