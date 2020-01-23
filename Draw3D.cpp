#include "Draw3D.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void Draw3D::DrawCube()
{
	glBegin(GL_QUADS);

	//front

	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);

	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);

	glEnd();
}

void Draw3D::DrawSphere()
{
}

void Draw3D::DrawCustomMesh()
{
}

void Draw3D::DrawPlane()
{
}

void Draw3D::DrawCylinder()
{
}

void Draw3D::DrawPyramid()
{
}
