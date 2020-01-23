#pragma once

class Shaders
{
public:
	static void LoadShader();
	static unsigned CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	static unsigned int CompileShader(unsigned int type, const std::string source);

private:

};