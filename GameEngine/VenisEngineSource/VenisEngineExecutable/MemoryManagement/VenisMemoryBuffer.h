#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>
#include <assert.h>
//Class Started by RJ Bourdelais


class VenisBufferManager
{
public:
private:

	

};

template <typename T>
class VenisBuffer
{
public:
	

	VenisBuffer() {}
	~VenisBuffer() { std::cout << "destroying VenisBuffer" << std::endl; delete[] memoryBuffer; }
	
	void NewBuffer(T size, int count)
	{
		memoryBuffer = new memoryBuffer[sizeof(T) * count];
		pInt = new (memoryBuffer) T();
	}

	

private:
	void* AddToBuffer(T addedData)
	{
		int* pos = new (memoryBuffer + sizeof(T)) T();
		return pos;
	}


	static std::unique_ptr <VenisBuffer> Instance;
	unsigned char* memoryBuffer;
	int* pInt;
};


template <typename T>
class VenisPointer
{
public:
	VenisPointer() {}
	~VenisPointer() { std::cout << "destructor" << std::endl; }

	void* operator new (size_t size) { return VenisBuffer::AddToBuffer(this); }
	 void operator delete (void * p) { std::cout << "Deleting Mems" << std::endl; }


	 friend VenisBuffer<T>;

private:

};

class Temporary : public  VenisPointer<Temporary>
{
public:
	Temporary() { justAValue = 5; std::cout << justAValue << std::endl; }
	~Temporary() { std::cout << "Destroying Temp" << std::endl; }

	int justAValue;

};