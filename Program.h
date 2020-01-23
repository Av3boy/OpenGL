#pragma once

#include <iostream>

using namespace std;

class OpenGL
{

public:

	struct Window
	{
		int windowWidth = 480;
		int windoHeight = 640;

		string windowName = "";

	} window;

	void Start();
	void FrameTick(GLFWwindow* window);
	void Draw(GLFWwindow* window);

	static void GLClearError();

	static bool GLLogCall(const char* function, const char* file, int line);

private:
	

};