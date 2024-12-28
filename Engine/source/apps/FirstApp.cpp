#include "precomp.h"
#include "FirstApp.h"

namespace MeletEngine::Apps
{
	FirstApp::FirstApp()
	{
		createPipelineLayout();
		createPipeline();
		createCommandBuffers();
	}

	FirstApp::~FirstApp()
	{
		vkDestroyPipelineLayout(veDevice.device(), pipelineLayout, nullptr);
	}

	void FirstApp::run()
	{
		while (!veWindow.shouldClose())
		{
			glfwPollEvents();
		}
	}

	void FirstApp::createPipelineLayout()
	{
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;
		if (vkCreatePipelineLayout(veDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create pipeline layout");
		}
	}

	void FirstApp::createPipeline()
	{
		auto pipeLineConfig = VePipeline::defaultPipeLineConfigInfo(veSwapChain.width(), veSwapChain.height());
		pipeLineConfig.renderPass = veSwapChain.getRenderPass();
		pipeLineConfig.pipelineLayout = pipelineLayout;
		vePipeline = std::make_unique<VePipeline>(
			veDevice,
			"shaders/simple/simple_shader.vert.spv",
			"shaders/simple/simple_shader.frag.spv",
			pipeLineConfig
		);
	}

	void FirstApp::createCommandBuffers()
	{
	}

	void FirstApp::drawFrame()
	{
	}

}