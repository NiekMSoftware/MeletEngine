#pragma once

namespace MeletEngine
{
	class VeModel
	{
	public:
		struct Vertex
		{
			glm::vec2 position;
			glm::vec3 color;

			static std::vector<VkVertexInputBindingDescription> getBindingDescription();
			static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
		};

		VeModel(VeDevice& device, const std::vector<Vertex>& vertices);
		~VeModel();

		VeModel(const VeModel&) = delete;
		VeModel operator=(const VeModel&) = delete;

		void bind(VkCommandBuffer commandBuffer) const;
		void draw(VkCommandBuffer commandBuffer) const;

	private:
		void createVortexBuffer(const std::vector<Vertex>& vertices);

		VeDevice& veDevice;
		VkBuffer vertexBuffer;
		VkDeviceMemory vertexBufferMem;
		uint32_t vertexCount;
	};
}
