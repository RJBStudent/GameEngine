#pragma once
#ifndef PART_H
#define PART_H
#include <string>

class Part
{
public:
	Part();
	virtual ~Part();

	virtual void Update();

	std::string GetName();

protected:
	//name is for debug purposes
	std::string mName;

};

#endif PART_H