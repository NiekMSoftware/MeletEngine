#pragma once

namespace MeletEngine
{
	class VeWindow
	{
	public:
		VeWindow(int w, int h, const std::string& name);
		~VeWindow();

		VeWindow(const VeWindow&) = delete;
		VeWindow& operator=(const VeWindow&) = delete;

		bool shouldClose() const { return glfwWindowShouldClose(window); }
		VkExtent2D getExtent() const { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }

		bool wasWindowResized() const { return frameBufferResized; }
		void resetWindowResizedFlag() { frameBufferResized = false; }

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	private:
		static void frameBufferResizedCallback(GLFWwindow* window, int width, int height);
		void initWindow();

		int width;
		int height;
		bool frameBufferResized = false;

		const std::string& engineName;

		GLFWwindow* window;
	};
}
