#pragma once

// Credits go to Brendan Galea for this implementation.

namespace MeletEngine
{
	struct SwpChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;

		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	struct QueueFamilyIndices
	{
		uint32_t graphicsFamily;
		uint32_t presentFamily;

		bool graphicsFamilyHasValue = false;
		bool presentFamilyHasValue = false;
		bool isComplete() const { return graphicsFamilyHasValue && presentFamilyHasValue; }
	};

	class VeDevice
	{
	public:
#ifdef NDEBUG
		const bool enableValidationLayers = false;
#else
		const bool enableValidationLayers = true;
#endif

		VeDevice(VeWindow& window);
		~VeDevice();

		// Not copyable or moveable
		VeDevice(const VeDevice&) = delete;
		VeDevice& operator=(const VeDevice&) = delete;
		VeDevice(VeDevice&) = delete;
		VeDevice& operator=(VeDevice&) = delete;

		VkCommandPool getCommandPool() const { return commandPool; }
		VkDevice device() const { return m_device; }
		VkSurfaceKHR surface() const { return m_surface; }
		VkQueue graphicsQueue() const { return m_graphicsQueue; }
		VkQueue presentQueue() const { return m_presentQueue; }

		SwpChainSupportDetails getSwapChainSupport() { return querySwapChainSupport(physicalDevice); }
		uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) const;
		QueueFamilyIndices findPhysicalQueueFamilies() { return findQueueFamilies(physicalDevice); }
		VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features) const;

		// buffer helper functions
		void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory) const;

		VkCommandBuffer beginSingleTimeCommands() const;
		void endSingleTimeCommands(VkCommandBuffer commandBuffer) const;

		void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size) const;
		void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layerCount) const;

		void createImageWithInfo(const VkImageCreateInfo& imageInfo, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory) const;
		VkPhysicalDeviceProperties VkProperties;

	private:
		void createInstance();
		void setupDebugMessenger();
		void createSurface();
		void pickPhysicalDevice();
		void createLogicalDevice();
		void createCommandPool();

		bool isDeviceSuitable(VkPhysicalDevice device) const;
		std::vector<const char*> getRequiredExtensions() const;
		bool checkValidationLayerSupport() const;
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device) const;
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		void hasGFLWRequiredInstanceExtensions() const;
		bool checkDeviceExtensionSupport(VkPhysicalDevice device) const;
		SwpChainSupportDetails querySwapChainSupport(VkPhysicalDevice device) const;

		VkInstance instance;
		VkDebugUtilsMessengerEXT debugMessenger;
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
		VeWindow& window;
		VkCommandPool commandPool;

		VkDevice m_device;
		VkSurfaceKHR m_surface;
		VkQueue m_graphicsQueue;
		VkQueue m_presentQueue;

		const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
		const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
	};
}
