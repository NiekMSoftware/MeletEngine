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
	private:
		void initWindow();

		const int width;
		const int height;

		const std::string& engineName;

		GLFWwindow* window;
	};
}
