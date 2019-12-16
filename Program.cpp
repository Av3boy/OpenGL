#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Input.h"
#include "Program.h"
#include "AudioPlayer.h"
#include "LoadShaders.hpp"


#include <Windows.h>
//#include "Draw2D.h"
#pragma comment(lib, "winmm.lib")

using namespace std;

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	OpenGL opengl;

	window = glfwCreateWindow(opengl.window.windoHeight, opengl.window.windowWidth, opengl.window.windowName.c_str(), NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW Init error!";
	}

	// Create and compile our GLSL program from the shaders
	/*GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");


	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// An array of 3 vectors which represents 3 vertices
	static const GLfloat g_vertex_buffer_data[] = {
	   -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f,
	};
	// This will identify our vertex buffer
	GLuint vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);*/


	opengl.Start();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		opengl.FrameTick();
		// 1st attribute buffer : vertices
		/*glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);

		// Use our shader
		glUseProgram(programID);
		// Draw triangle...*/

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void OpenGL::Start()
{
	AudioPlayer audio;
	audio.PlayAudioFromFile("barradeen-bedtime-after-a-coffee.wav", 0);
	audio.PlayAudioFromFile("solid.wav", 0);
}

void OpenGL::FrameTick()
{
	//Draw2D draw2d;
	//draw2d.DrawTriangle();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glColor3f(0, 0, 0);

	glVertex3f(0.0f, 0.5f, 0.0f);
	glColor3f(1, 1, 1);

	glVertex3f(0.5f, -0.5f, 0.0f);
	glColor3f(122, 122, 122);
	glEnd();

}
