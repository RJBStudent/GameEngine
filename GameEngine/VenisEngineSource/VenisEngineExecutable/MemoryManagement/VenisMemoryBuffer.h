#pragma once

#include <iostream>
#include <memory>
#include <typeinfo>
#include <assert.h>
#include <map>
#include <new.h>
//Class Started by RJ Bourdelais

class VenisBufferParent
{
public:
	VenisBufferParent() {}
	virtual void NewBuffer(size_t size, int count) = 0;
	virtual void* AddToBuffer(size_t size) = 0;
private:

};


template <typename T>
class VenisBuffer : public VenisBufferParent
{
public:
	

	VenisBuffer<T>() {}
	~VenisBuffer() { std::cout << "destroying VenisBuffer" << std::endl; delete[] memoryBuffer; }
	
	virtual void NewBuffer(size_t size, int count)
	{
		memoryBuffer = new unsigned char [size * count];
		pInt = new ((void*)memoryBuffer) (T);
	}



	virtual void* AddToBuffer(size_t size)
	{
		int* pos = new ((void*)(memoryBuffer + sizeof(T))) T;
		return pos;
	}

private:

	unsigned char* memoryBuffer;
	int* pInt;
};


class VenisBufferManager
{
public:
	static VenisBufferManager* GetInstance()
	{
		if (!VenisBufferManager::Instance)
		{
			VenisBufferManager::Instance = new VenisBufferManager();
		}
		return VenisBufferManager::Instance;
	}

	static void DestroyInstance()
	{
		if (VenisBufferManager::Instance)
		{
			delete VenisBufferManager::Instance;
		}
	}
	
	template <typename T>
	 VenisBufferParent* CreateBuffer(int count) 
	{
		VenisBuffer<T>* nVB = new VenisBuffer<T>();
		nVB->NewBuffer(1, count);
		bufferList.insert(std::make_pair(1, nVB));
		return nVB;
	} // Call new Buffer in VenisBuffer
	
	void* AddToBuffer(size_t size) 
	{

		bufferList[size]->AddToBuffer(size);
		return 0;

	}
	//Get size of vbp to get proper buffer, add to that buffer, return pointer

private:
	static VenisBufferManager* Instance;

	VenisBufferManager() {}
	~VenisBufferManager() {}

	std::map<int, VenisBufferParent*> bufferList;
};


template <typename T>
class VenisPointer
{
public:
	VenisPointer() {}
	~VenisPointer() { std::cout << "destructor" << std::endl; }

	void* operator new (size_t size) { return VenisBufferManager::GetInstance()->AddToBuffer(size); }
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