#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <iostream>

struct Input
{
	struct KeyBorad {
		//Call key
		static void HandleKey(GLFWwindow* window, int key, int scancode, int action, int mods) {
			KeyBorad& handler = *reinterpret_cast<KeyBorad*>(glfwGetWindowUserPointer(window));
			handler.handleKeyImpl(window, key, scancode, action, mods);
		}
		void handleKeyImpl(GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (key == GLFW_KEY_F && action == GLFW_PRESS)
			{
				std::cout << key << " pressed.";
			}
		}

		//
		static void HandleCharacter(GLFWwindow* window, unsigned int codepoint) {
			KeyBorad& handler = *reinterpret_cast<KeyBorad*>(glfwGetWindowUserPointer(window));
			handler.handleCharacterImpl(window, codepoint);
		}
		void handleCharacterImpl(GLFWwindow* window, unsigned int codepoint) {
			std::cout << codepoint;
		}
	};


	struct Mouse {
		GLFWcursor* cursor = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
			{

			}
		}

		//Called when mouse hovers over window
		bool cursor_enter_callback(GLFWwindow* window, int entered)
		{
			if (entered)
			{
				// The cursor entered the content area of the window
			}
			else
			{
				// The cursor left the content area of the window
			}
		}

		void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
		{
		}

		void GetMousePosition(GLFWwindow* window)
		{
			double xpos, ypos;
			glfwGetCursorPos(window, &xpos, &ypos);
		}

		void HideCursor()
		{
			glfwDestroyCursor(cursor);
		}

		void ShowCursor(GLFWwindow* window)
		{
			glfwSetCursor(window, cursor);
		}
	};

	struct JoyStick
	{
		void joystick_callback(int jid, int event)
		{
			if (event == GLFW_CONNECTED)
			{
				// The joystick was connected
			}
			else if (event == GLFW_DISCONNECTED)
			{
				// The joystick was disconnected
			}
		}
	};

	struct Monitor
	{

	};

};