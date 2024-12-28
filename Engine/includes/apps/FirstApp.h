#pragma once

namespace MeletEngine::Apps
{
	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp operator=(const FirstApp&) = delete;

		void run();
	private:
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		VeWindow veWindow{ WIDTH, HEIGHT, "Hello, Vulkan!" };
		VeDevice veDevice{veWindow};
		VeSwapChain veSwapChain{ veDevice, veWindow.getExtent() };

		std::unique_ptr<VePipeline> vePipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
	};
}