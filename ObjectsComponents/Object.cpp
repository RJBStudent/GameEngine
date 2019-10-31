#include "Object.h"
#include <iostream>

Object::Object()
{
	std::cout << "Base Object Contructor \n";
}

Object::~Object()
{
	std::cout << "Base Object Destructor \n";
}

void Object::Update()
{
	std::cout << "Base Object Update \n";
}

void Object::Start()
{
	std::cout << "Base Object Start \n";
}