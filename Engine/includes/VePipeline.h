#pragma once

namespace MeletEngine
{
	class VeDevice;
	struct PipelineConfigInfo{};

	class VePipeline
	{
	public:
		VePipeline(
			VeDevice& device,
			const std::string& vertFilePath,
			const std::string& fragFilePath,
			const PipelineConfigInfo& config);
		~VePipeline();

		VePipeline(const VePipeline&) = delete;
		void operator=(const VePipeline&) = delete;

		static PipelineConfigInfo defaultPipeLineConfigInfo(uint32_t width, uint32_t height);

	private:
		static std::vector<char> readFile(const std::string& filePath);

		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& config);
		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		VeDevice& veDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}
