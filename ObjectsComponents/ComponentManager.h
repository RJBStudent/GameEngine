#pragma once
#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H
#include "Component.h"
#include "Object.h"
#include <map>

static class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();

	void Update();
	Component GetComponent();

private:
	std::map<Object, Component> objectToComponentMap;
};

#endif COMPONENTMANAGER_H