#include "EventHandler.h"
#include "Engine.h"

EventHandler::EventHandler() 
{
}

EventHandler::~EventHandler() 
{
}

void EventHandler::handle_event(SDL_Event event)
{
	switch (event.type)
	{
	case SDL_QUIT:
		Engine::RUNNING = false;
		break;
	case SDL_MOUSEMOTION:
		//printf("X: %d, Y: %d\n", event.motion.x, event.motion.y);
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) 
		{
		case SDLK_a:
			printf("A PRESSED");
			break;
		}
		break;
	}
}