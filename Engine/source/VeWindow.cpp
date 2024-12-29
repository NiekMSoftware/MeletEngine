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
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		window = glfwCreateWindow(width, height, engineName.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(window, this);
		glfwSetFramebufferSizeCallback(window, frameBufferResizedCallback);
	}

	void VeWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create window surface");
		}
	}

	void VeWindow::frameBufferResizedCallback(GLFWwindow* window, int width, int height)
	{
		auto veWindow = reinterpret_cast<VeWindow*>(glfwGetWindowUserPointer(window));
		veWindow->frameBufferResized = true;
		veWindow->width = width;
		veWindow->height = height;
	}
}
