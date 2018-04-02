#include "Engine.h"

bool Engine::RUNNING = false;

Engine::Engine(std::shared_ptr<Window> game_window) 
{
	g_window = game_window;
}

Engine::~Engine() 
{
}

bool Engine::start_up()
{
	RUNNING = true;

	s_renderer->start(g_window);
	s_entity_manager->start();

	return 1;
}

bool Engine::shut_down()
{
	SDL_GL_DeleteContext(g_window->get_gl_context());
	SDL_DestroyWindow(g_window->get_window_handler());
	SDL_Quit();

	return 1;
}

void Engine::main_loop() 
{
	while (RUNNING) 
	{
		if(SDL_PollEvent(game_event))
			s_event_handler->handle_event(*game_event);

		update();
		render();
	}
}

void Engine::render() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	s_renderer->render();
}

void Engine::update() 
{
	SDL_GL_SwapWindow(g_window->get_window_handler());
}