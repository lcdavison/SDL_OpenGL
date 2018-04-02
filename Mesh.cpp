#include "Mesh.h"

Mesh::Mesh(std::vector<GLfloat> vertices, std::vector<GLint> indices) 
{
	vertex_count = indices.size();

	glGenVertexArrays(1, &vao_id);
	glBindVertexArray(vao_id);

	/*---VERTEX BUFFER---*/
	GLuint vbo_id;
	glGenBuffers(1, &vbo_id);
	vbos.insert(std::pair<std::string, GLuint>("VERTEX", vbo_id));
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

	/*---INDEX BUFFER---*/
	glGenBuffers(1, &vbo_id);
	vbos.insert(std::pair<std::string, GLuint>("INDEX", vbo_id));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLint), &indices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Mesh::~Mesh()
{
}

void Mesh::render() 
{
	glBindVertexArray(vao_id);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawElements(GL_TRIANGLES, vertex_count, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}