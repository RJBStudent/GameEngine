#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>
//Class Started by RJ Bourdelais

class VenisBuffer
{
public:
	
	VenisBuffer() {}
	~VenisBuffer() {}

	template <typename T>
	void NewBuffer(T type, int size)
	{
		memoryBuffer = std::make_unique<unsigned char[]>(sizeof(T) * size);
	}
		

private:

	std::unique_ptr<unsigned char[]> memoryBuffer;
};

template <typename T>
class VenisPointer
{
public:
	VenisPointer() {}
	~VenisPointer() { std::cout << "destructor" << std::endl; }

	 void* operator new (size_t size) { std::cout << "Allocating Mems" << std::endl;
	std::unique_ptr<T> n = std::make_unique<T>(size);
	return 0; }
	 void operator delete (void * p) { std::cout << "Deleting Mems" << std::endl; }

	std::unique_ptr<T> thisVal;

private:

};

class Temporary : public  VenisPointer<Temporary>
{
public:
	Temporary() {}
	~Temporary() {}

};