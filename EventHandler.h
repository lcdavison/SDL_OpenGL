#pragma once

#include "Common.h"

class EventHandler 
{
public:
	EventHandler();
	~EventHandler();

	void handle_event(SDL_Event);

};