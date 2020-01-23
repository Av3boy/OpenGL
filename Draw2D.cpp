#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Program.h"
#include "ErrorHandling.h"
#include "Draw2D.h"

#include <stdlib.h>
#include <vector>
#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) Error::GLClearError;\
	x;\
	ASSERT(Error::GLLogCall(#x, __FILE__, __LINE__))

void Draw2D::DrawTriangle()
{
	float pos[] = {
	-0.5f, -0.5f,
	 0.0f,  0.5f,
	 0.5f, -0.5f,
	};

	LoadBuffers(pos, (sizeof(pos) / sizeof(*pos)));

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Draw2D::DrawQuad()
{
	float pos[] = {
		-0.5f, -0.5f, // 1
		 0.5f, -0.5f, // 2
		 0.5f,  0.5f, // 3
		-0.5f,  0.5f, // 4
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	LoadBuffers(pos, 12); //(sizeof(pos) / sizeof(*pos)));
	LoadIndexBuffer(indices, 6);

	GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

}

void Draw2D::LoadBuffers(float pos[], int size)
{
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), pos, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
}

void Draw2D::LoadIndexBuffer(unsigned int pos[], int size)
{
	unsigned int ibo; //index buffer object
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), pos, GL_STATIC_DRAW);
}