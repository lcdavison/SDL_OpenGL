#include "Shader.h"

GLuint Shader::CreateShader(GLenum shader_type, GLchar* shader_code) 
{
	GLuint shader_id = glCreateShader(shader_type);

	glShaderSource(shader_id, 1, &shader_code, NULL);

	glCompileShader(shader_id);

	GLint success;
	GLchar info_log[512];

	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

	if(!success) 
	{
		glGetShaderInfoLog(shader_id, 512, NULL, info_log);
		std::cout << "SHADER COMPILE ERROR : " << info_log << std::endl;
		return 0;
	}

	return shader_id;
}