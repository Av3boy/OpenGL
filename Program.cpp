#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <iostream>

#include "Input.h"
#include "Program.h"
#include "AudioPlayer.h"
#include "Draw2D.h"
#include "LoadShaders.h"

#include <Windows.h>

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

	opengl.Start();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		opengl.FrameTick(window);

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
	/*AudioPlayer audio;
	audio.PlayAudioFromFile("barradeen-bedtime-after-a-coffee.wav", 0);
	audio.PlayAudioFromFile("solid.wav", 0);*/

	Shaders::LoadShader();

}

void OpenGL::FrameTick(GLFWwindow* window)
{
	OpenGL::Draw(window);

	Input::KeyBorad keyboard;
	glfwSetWindowUserPointer(window, &keyboard);
	glfwSetKeyCallback(window, Input::KeyBorad::HandleKey);

	//Calculate FPS

}

void OpenGL::Draw(GLFWwindow* window)
{
	Draw2D::DrawQuad();
}
