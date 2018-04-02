#include "Window.h"

Window::Window() 
{
	if (!create_window()) { exit(EXIT_FAILURE); }
}

Window::~Window() 
{
}

bool Window::create_window() 
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	window = SDL_CreateWindow("SDL WINDOW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

	SDL_SetWindowResizable(window, SDL_TRUE);

	if (nullptr == window) { std::cout << "Failed to create SDL window" << std::endl; return false; }

	gl_context = SDL_GL_CreateContext(window);

	glewExperimental = true;

	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return false;
	}

	glViewport(0, 0, WIDTH, HEIGHT);

	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);

	return true;
}

SDL_Window* Window::get_window_handler() { return window; }

SDL_GLContext Window::get_gl_context() { return gl_context; }

GLfloat Window::aspect_ratio() 
{
	return (float) WIDTH / (float) HEIGHT;
}