#pragma once

#include <iostream>

#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>

class Window 
{
private:
	const GLint WIDTH = 1280, HEIGHT = 720;

	bool create_window();

	SDL_Window* window;
	SDL_GLContext gl_context;

public:
	Window();
	~Window();

	SDL_Window* get_window_handler();
	SDL_GLContext get_gl_context();

	GLfloat aspect_ratio();
};