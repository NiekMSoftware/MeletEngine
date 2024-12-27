#include "precomp.h"
#include "VeWindow.h"

namespace MeletEngine
{
	VeWindow::VeWindow(int w, int h, const std::string& name)
		: width(w), height(h), engineName(name)
	{
		initWindow();
	}

	VeWindow::~VeWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void VeWindow::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, engineName.c_str(), nullptr, nullptr);
	}
}