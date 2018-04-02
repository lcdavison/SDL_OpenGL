#include "Common.h"
#include "Window.h"
#include "Engine.h"

int main(int argc, char *argv[]) 
{
	std::shared_ptr<Window> window = std::make_shared<Window>();	//	Window Game Specific
	std::unique_ptr<Engine> engine = std::make_unique<Engine>(window);

	if (!engine->start_up()) { exit(EXIT_FAILURE); }

	engine->main_loop();

	if (!engine->shut_down()) { exit(EXIT_FAILURE); }

	return EXIT_SUCCESS;
}