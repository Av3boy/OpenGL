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
	void FrameTick();

private:
	

};