#pragma once

#include "Common.h"

class Mesh 
{
private:
	GLuint vao_id;
	GLint vertex_count;
	std::map<std::string, GLuint> vbos;

public:
	Mesh(std::vector<GLfloat>, std::vector<GLint>);
	~Mesh();

	void render();
};