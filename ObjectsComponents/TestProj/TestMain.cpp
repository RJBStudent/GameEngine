#include "PartManager.h"
#include "Object.h"
#include "TestPart.h"
#include <iostream>

int main()
{
	PartManager::GetInstance().init();

	Object o;
	o.AddPart<TestPart>();
	std::cout << o.GetPart<TestPart>()->GetName();

	PartManager::GetInstance().CleanUp();
}
