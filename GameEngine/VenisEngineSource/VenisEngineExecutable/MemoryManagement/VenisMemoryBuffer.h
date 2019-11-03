#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>
#include <assert.h>
//Class Started by RJ Bourdelais

class VenisBuffer
{
public:
	

	static VenisBuffer* GetInstance() { if (Instance == NULL) Instance = new VenisBuffer(); return Instance; }

	static void cleanInstance() { delete Instance; }

	template <typename T>
	void NewBuffer(T size)
	{
		memoryBuffer = std::make_unique<unsigned char[]>(size);
	}

	template <typename T>
	void AddToBuffer(T addedData)
	{
		
		std::memcpy(&memoryBuffer, addedData, sizeof(addedData));
		std::cout << memoryBuffer[0] << std::endl;
	}


private:

	VenisBuffer() {}
	~VenisBuffer() { std::cout << "destroying VenisBuffer" << std::endl; }

	static VenisBuffer* Instance;
	std::unique_ptr<unsigned char[]> memoryBuffer;
};

VenisBuffer* VenisBuffer::Instance = NULL;

template <typename T>
class VenisPointer
{
public:
	VenisPointer() {VenisBuffer::GetInstance()->AddToBuffer(this); }
	~VenisPointer() { std::cout << "destructor" << std::endl; }

	 void* operator new (size_t size) { std::cout << "Type Not Allowed Asserting" << std::endl;
	 assert(false);
		return 0; }
	 void operator delete (void * p) { std::cout << "Deleting Mems" << std::endl; }

	//std::unique_ptr<T> thisVal;

private:

};

class Temporary : public  VenisPointer<Temporary>
{
public:
	Temporary() { justAValue = 5; std::cout << justAValue << std::endl; }
	~Temporary() { std::cout << "Destroying Temp" << std::endl; }

	int justAValue;

};