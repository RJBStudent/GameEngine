#pragma once


//Class Started by RJ Bourdelais
template <typename T>
class Buffer()
{
public:

	Buffer();
	~Buffer();

	void NewBuffer(T type, int size)
	{
		unsigned char b[sizeof(T) * size];
		mBuffer = b;
	}

private:
	unsigned char mBuffer[];
}

class MemoryManager()
{
public:
	//Const Memory Size to Allocate
	
	MemoryManager();
	~MemoryManager();

private:
	std::unique_ptr<unsigned char> memoryList[];
}