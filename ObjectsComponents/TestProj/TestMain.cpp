#include "PartManager.h"
#include "Object.h"
#include <iostream>

int main()
{
	PartManager::GetInstance().init();

	Object o;
	o.AddPart<TestPart>();
	std::cout << o.GetPart<TestPart>()->GetName() << std::endl;

	PartManager::GetInstance().CleanUp();
}
