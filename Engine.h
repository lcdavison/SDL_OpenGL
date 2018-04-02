#pragma once

#include "EventHandler.h"
#include "Common.h"
#include "Window.h"
#include "Renderer.h"
#include "EntityManager.h"

class Engine 
{
private:
	std::shared_ptr<Window> g_window;
	std::shared_ptr<Renderer> s_renderer = std::make_shared<Renderer>();
	std::shared_ptr<EventHandler> s_event_handler = std::make_shared<EventHandler>();
	std::shared_ptr<EntityManager> s_entity_manager = std::make_shared<EntityManager>();

	SDL_Event* game_event = new SDL_Event();

	void render();
	void update();

public:
	Engine(std::shared_ptr<Window>);
	~Engine();

	static bool RUNNING;

	bool start_up();
	bool shut_down();

	void main_loop();
};