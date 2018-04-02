#pragma once

#include "Common.h"
#include "Window.h"
#include "Shader.h"
#include "Mesh.h"

class Renderer 
{
private:
	std::shared_ptr<Window> game_window;

	GLuint program_id;
	GLuint vertex_shader, fragment_shader;

	std::map<std::string, GLuint> uniforms;

	GLfloat fov = glm::radians(45.0f);
	GLfloat z_near = 0.1f;
	GLfloat z_far = 1000.0f;

	glm::mat4 projection;
	glm::mat4 view_matrix;
	glm::mat4 model_matrix;

	Mesh* mesh;

	/*---SHADER---*/
	void link_program();
	bool create_uniform(GLchar*);
	bool set_matrix4_uniform(GLchar*, glm::mat4);

	/*---TRANSFORM---*/
	glm::mat4 projection_matrix();

public:
	Renderer();
	~Renderer();

	void start(std::shared_ptr<Window>);
	void stop();

	void render();
};
