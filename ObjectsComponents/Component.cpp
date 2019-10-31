#include "Component.h"
#include<iostream>

Component::Component()
{
	std::cout << "Base Component Constructor \n";
}

Component::~Component()
{
	std::cout << "Base Component Destructor \n";
}

void Component::Update()
{
	std::cout << "Base Component Update \n";
}