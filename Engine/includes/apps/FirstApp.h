#pragma once

namespace MeletEngine::Apps
{
	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();
	private:
		VeWindow veWindow{ WIDTH, HEIGHT, "Hello, Vulkan!" };
		VePipeline vePipeline{"shaders/simple/simple_shader.vert.spv", "shaders/simple/simple_shader.frag.spv"};
	};
}