#pragma once

class Error
{
public:

	static void GLClearError();

	static bool GLLogCall(const char* function, const char* file, int line);

private:

};