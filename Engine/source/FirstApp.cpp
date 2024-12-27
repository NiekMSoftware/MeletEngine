#include "precomp.h"
#include "FirstApp.h"

namespace MeletEngine::Apps
{
	void FirstApp::run()
	{
		while (!veWindow.shouldClose())
		{
			glfwPollEvents();
		}
	}

}