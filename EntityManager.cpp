#include "EntityManager.h"

EntityManager::EntityManager() 
{
}

EntityManager::~EntityManager() 
{
}

void EntityManager::start() 
{
	create_entity("Test");
	create_entity("Test");
	create_entity("Test_1");
}

void EntityManager::stop() 
{
}

void EntityManager::create_entity(std::string name) 
{
	std::map<std::string, Entity*>::iterator it = entities.find(name);

	if (it != entities.end()) 
	{
		name.append("_0");

		int end_num = 1;
		std::string test = name;

		for (int i = 0; i < entities.size(); i++) 
		{
			std::stringstream ss;
			std::string end = test.substr(test.find_first_of('_') + 1, std::string::npos);

			end_num = std::stoi(end) + 1;

			test = name.substr(0, name.find_first_of('_'));

			ss << "_" << end_num;
			ss >> end;

			test.append(end);

			it = entities.find(test);

			if (it == entities.end())
				break;
		}

		name.erase(name.find_first_of('_'), std::string::npos);

		name.append("_" + std::to_string(end_num));

		std::cout << name << std::endl;
	} 

	entities.insert(std::pair<std::string, Entity*>(name, new Entity(name)));

	std::cout << "MAP SIZE : " << entities.size() << std::endl;
}

std::list<Entity> EntityManager::retrieve_all_entities() 
{
	std::list<Entity> found;
	return found;
}

Entity EntityManager::find_entity_by_name(std::string name) 
{
	return nullptr;
}