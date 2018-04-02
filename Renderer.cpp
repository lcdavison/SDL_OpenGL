#include "Renderer.h"

Renderer::Renderer() 
{
}

Renderer::~Renderer() 
{
}

void Renderer::start(std::shared_ptr<Window> window) 
{
	glEnable(GL_DEPTH_TEST);

	game_window = window;

	program_id = glCreateProgram();

	vertex_shader = Shader::CreateShader(GL_VERTEX_SHADER, (GLchar*) Utils::read_file("F:/OpenGL/SDL_ENGINE/SDL_ENGINE/vertex.vs").c_str());
	glAttachShader(program_id, vertex_shader);

	fragment_shader = Shader::CreateShader(GL_FRAGMENT_SHADER, (GLchar*) Utils::read_file("F:/OpenGL/SDL_ENGINE/SDL_ENGINE/fragment.fs").c_str());
	glAttachShader(program_id, fragment_shader);

	link_program();

	create_uniform("projection");
	create_uniform("view");
	create_uniform("model");

	std::vector<GLfloat> vertices = 
	{
		/*---VERTICES---*/		/*---COLOURS---*/
		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,		0.0f, 1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,		0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,		0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, -0.5f,		0.0f, 0.0f, 1.0f
	};

	std::vector<GLint> indices = 
	{
		// Front face
		0, 1, 3, 3, 1, 2,
		// Top Face
		4, 0, 3, 5, 4, 3,
		// Right face
		3, 2, 7, 5, 3, 7,
		// Left face
		6, 1, 0, 6, 0, 4,
		// Bottom face
		2, 1, 6, 2, 6, 7,
		// Back face
		7, 6, 4, 7, 4, 5
	};

	mesh = new Mesh(vertices, indices);
}

void Renderer::stop()
{
}

void Renderer::render() 
{	
	projection = projection_matrix();
	view_matrix = glm::lookAt(glm::vec3(4, 3, 0), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	
	model_matrix = glm::mat4(1.0f);	//	Identity Matrix
	model_matrix = glm::translate(model_matrix, glm::vec3(1, 1, 0));
	model_matrix = glm::rotate(model_matrix, (GLfloat) SDL_GetTicks() * 0.001f, glm::vec3(0.5f, 1.0f, 0.0f));

	glUseProgram(program_id);

	set_matrix4_uniform("projection", projection);
	set_matrix4_uniform("view", view_matrix);
	set_matrix4_uniform("model", model_matrix);

	mesh->render();

	glUseProgram(0);
}

/*---SHADER RELATED---*/

void Renderer::link_program() 
{
	glLinkProgram(program_id);

	GLint success;
	GLchar info_log[512];

	glGetProgramiv(program_id, GL_LINK_STATUS, &success);

	if (!success) 
	{
		glGetProgramInfoLog(program_id, 512, NULL, info_log);
		std::cout << "PROGRAM ERROR : " << info_log << std::endl;
	}

	if(vertex_shader != 0)	glDetachShader(program_id, vertex_shader);
	if (fragment_shader != 0)	glDetachShader(program_id, fragment_shader);

	glValidateProgram(program_id);

	glGetProgramiv(program_id, GL_VALIDATE_STATUS, &success);

	if (!success) 
	{
		glGetProgramInfoLog(program_id, 512, NULL, info_log);
		std::cout << "PROGRAM ERROR : " << info_log << std::endl;
	}
}

bool Renderer::create_uniform(GLchar* name)
{
	GLuint uniform_id = glGetUniformLocation(program_id, name);

	if (uniform_id == -1) { printf("Failed To Create Uniform : Uniform Does Not Exist"); return false; }

	uniforms.insert(std::pair<std::string, GLuint>(name, uniform_id));

	return true;
}

bool Renderer::set_matrix4_uniform(GLchar* name, glm::mat4 matrix)
{
	GLuint uniform_id;
	std::map<std::string, GLuint>::iterator it = uniforms.find(name);

	if (it == uniforms.end()) { printf("Uniform Does Not Exist"); return false; }

	uniform_id = it->second;

	glUniformMatrix4fv(uniform_id, 1, GL_FALSE, glm::value_ptr(matrix));

	return true;
}

/*---TRANSFORM RELATED---*/

glm::mat4 Renderer::projection_matrix() 
{
	glm::mat4 projection_matrix = glm::mat4(1.0f);
	projection_matrix = glm::perspective(fov, game_window->aspect_ratio(), z_near, z_far);

	return projection_matrix;
}