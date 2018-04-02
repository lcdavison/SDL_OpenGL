#pragma once

#include "Common.h"

class Entity 
{
private:

public:
	Entity(std::string);
	~Entity();

	/*---PROPERTIES---*/
	std::string name;
	//	TRANSFORM - To store position, rotation, and scale data
};
