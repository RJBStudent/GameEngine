#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>
#include <assert.h>
#include <map>
//Class Started by RJ Bourdelais

//template <typename T>
class VenisBufferManager
{
public:
	VenisBufferManager* GetInstance() { if (!Instance) { Instance = new VenisBufferManager(); } return Instance; }

	void DestroyInstance() { if (Instance) { delete Instance; } }
	
	VenisBufferParent* CreateBuffer(typename T, int count) 
	{
		VenisBuffer<T> nVB = new VenisBuffer<T>();
		nVB.NewBuffer(T, count);
		bufferList.insert(sizeof(T), nVB);
		return nVB;
	} // Call new Buffer in VenisBuffer
	void* AddToBuffer(VenisBufferParent vbp) {}; //Get size of vbp to get proper buffer, add to that buffer, return pointer

private:
	VenisBufferManager* Instance = NULL;

	VenisBufferManager() {}
	~VenisBufferManager() {}

	std::map<int, VenisBufferParent> bufferList;

};

class VenisBufferParent
{
public:
	VenisBufferParent() {}
};

template <typename T>
class VenisBuffer : public VenisBufferParent
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

	void* operator new (size_t size) { return VenisBufferManager::GetInstance()->(*this); }
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