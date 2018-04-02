#pragma once

#include "Common.h"
#include "Entity.h"

class EntityManager 
{
private:
	std::map<std::string, Entity*> entities;

public:
	EntityManager();
	~EntityManager();

	void start();
	void stop();

	void create_entity(std::string);
	std::list<Entity> retrieve_all_entities();
	Entity find_entity_by_name(std::string);

};