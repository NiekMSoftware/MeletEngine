﻿#pragma once

// Code implementation goes to Brendan Galea, thank you buddy

namespace MeletEngine
{
	class VeSwapChain
	{
	public:
		static constexpr int MAX_FRAMES_IN_FLIGHT = 2;

		VeSwapChain(VeDevice& deviceRef, VkExtent2D windowExtent);
		~VeSwapChain();

		VeSwapChain(const VeSwapChain&) = delete;
		void operator=(const VeSwapChain&) = delete;

		VkFramebuffer getFrameBuffer(int index) const { return swapChainFrameBuffers[index]; }
		VkRenderPass getRenderPass() const { return renderPass; }
		VkImageView getImageView(int index) const { return swapChainImageViews[index]; }
		size_t imageCount() const { return swapChainImages.size(); }
		VkFormat getSwapChainImageFormat() const { return swapChainImageFormat; }
		VkExtent2D getSwapChainExtent() const { return swpChainExtent; }
		uint32_t width() const { return swpChainExtent.width; }
		uint32_t height() const { return swpChainExtent.height; }

		float extentAspectRatio() const
		{
			return static_cast<float>(swpChainExtent.width) / static_cast<float>(swpChainExtent.height);
		}
		VkFormat findDepthFormat();

		VkResult acquireNextImage(uint32_t* imageIndex);
		VkResult submitCommandBuffers(const VkCommandBuffer* buffers, uint32_t* imageIndex);

	private:
		void createSwapChain();
		void createImageViews();
		void createDepthResources();
		void createRenderPass();
		void createFrameBuffers();
		void createSyncObjects();

		// Helper functions
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(
			const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(
			const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

		VkFormat swapChainImageFormat;
		VkExtent2D swpChainExtent;

		std::vector<VkFramebuffer> swapChainFrameBuffers;
		VkRenderPass renderPass;

		std::vector<VkImage> depthImages;
		std::vector<VkDeviceMemory> depthImageMemories;
		std::vector<VkImageView> depthImageViews;
		std::vector<VkImage> swapChainImages;
		std::vector<VkImageView> swapChainImageViews;

		VeDevice& device;
		VkExtent2D windowExtent;

		VkSwapchainKHR swapChain;

		std::vector<VkSemaphore> imageAvailableSemaphores;
		std::vector<VkSemaphore> renderFinishedSemaphores;
		std::vector<VkFence> inFlightFences;
		std::vector<VkFence> imagesInFlight;
		size_t currentFrame = 0;
	};
}