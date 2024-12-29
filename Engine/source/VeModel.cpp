#include "precomp.h"
#include "VeModel.h"

namespace MeletEngine
{
	VeModel::VeModel(VeDevice& device, const std::vector<Vertex>& vertices): veDevice(device)
	{
		createVortexBuffer(vertices);
	}

	VeModel::~VeModel()
	{
		vkDestroyBuffer(veDevice.device(), vertexBuffer, nullptr);
		vkFreeMemory(veDevice.device(), vertexBufferMem, nullptr);
	}

	void VeModel::createVortexBuffer(const std::vector<Vertex>& vertices)
	{
		vertexCount = static_cast<uint32_t>(vertices.size());
		assert(vertexCount >= 3 && "Vertex count must at least be 3!");

		VkDeviceSize bufferSize = sizeof(vertices[0]) * vertexCount;
		veDevice.createBuffer(
			bufferSize,
			VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
			VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
			vertexBuffer,
			vertexBufferMem
		);

		void* data;
		vkMapMemory(veDevice.device(), vertexBufferMem, 0, bufferSize, 0, &data);
		memcpy(data, vertices.data(), static_cast<size_t>(bufferSize));
		vkUnmapMemory(veDevice.device(), vertexBufferMem);
	}

	void VeModel::bind(VkCommandBuffer commandBuffer) const
	{
		VkBuffer buffers[] = { vertexBuffer };
		VkDeviceSize offsets[] = { 0 };
		vkCmdBindVertexBuffers(commandBuffer, 0, 1, buffers, offsets);
	}

	void VeModel::draw(VkCommandBuffer commandBuffer) const
	{
		vkCmdDraw(commandBuffer, vertexCount, 1, 0, 0);
	}

	std::vector<VkVertexInputBindingDescription> VeModel::Vertex::getBindingDescription()
	{
		std::vector<VkVertexInputBindingDescription> bindingDescriptions(1);

		bindingDescriptions[0].binding = 0;
		bindingDescriptions[0].stride = sizeof(Vertex);
		bindingDescriptions[0].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

		return bindingDescriptions;
	}

	std::vector<VkVertexInputAttributeDescription> VeModel::Vertex::getAttributeDescriptions()
	{
		std::vector<VkVertexInputAttributeDescription> attributeDescriptions(2);

		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[0].offset = offsetof(Vertex, position);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(Vertex, color);

		return attributeDescriptions;
	}
}
