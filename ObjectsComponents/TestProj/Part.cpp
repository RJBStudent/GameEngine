#include "Part.h"
#include<iostream>

Part::Part()
{
	mName = "base part";
	std::cout << "Base Part Constructor \n";
}

Part::~Part()
{
	std::cout << "Base Part Destructor \n";
}

void Part::Update()
{
	std::cout << "Base Part Update \n";
}

std::string Part::GetName()
{
	return mName;
}
