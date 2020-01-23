#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
using namespace std;

#include <sstream>
#include <iostream>
#include <Bits.h>

#include "ErrorHandling.h"

void Error::GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool Error::GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{

		stringstream ss;
		ss << hex << error;

		std::cout << "[OpenGL Error] (" << "0x" << ss.str() << ", " << error <<
			"): " << function <<
			" in file: " << file << " on line: " << line << "." << std::endl;
		return false;
	}
	return true;
}