#include "precomp.h"

#include "VeDevice.h"
#include "VePipeline.h"

namespace MeletEngine
{
	VePipeline::VePipeline(VeDevice& device, const std::string& vertFilePath, const std::string& fragFilePath,
		const PipelineConfigInfo& config) : veDevice(device)
	{
		createGraphicsPipeline(vertFilePath, fragFilePath, config);
	}

	VePipeline::~VePipeline()
	{
	}

	PipelineConfigInfo VePipeline::defaultPipeLineConfigInfo(uint32_t width, uint32_t height)
	{
		PipelineConfigInfo configInfo;
		return configInfo;
	}

	std::vector<char> VePipeline::readFile(const std::string& filePath)
	{
		std::ifstream file{filePath, std::ios::ate | std::ios::binary};

		if (!file.is_open())
		{
			throw std::runtime_error("Failed to open file: " + filePath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}

	void VePipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath,
		const PipelineConfigInfo& config)
	{
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);

		println("Vertex Shader Code Size: {}", vertCode.size());
		println("Fragment Shader Code Size: {}", fragCode.size());
	}

	void VePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
	{
		VkShaderModuleCreateInfo createInfo;
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(veDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create Shader Module");
		}
	}
}
