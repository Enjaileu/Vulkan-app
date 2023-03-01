#pragma once
#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>

#include "VulkanUtilities.h"

struct {
	vk::PhysicalDevice physicalDevice;
	vk::Device logicalDevice;
} mainDevice;

class VulkanRenderer
{
public:
	VulkanRenderer();
	~VulkanRenderer();
	int init(GLFWwindow* windowP);
	void clean();

private:
	GLFWwindow* window;
	vk::Instance instance;
	vk::Queue graphicsQueue;

	void createInstance();
	bool checkInstanceExtensionSupport(const std::vector<const char*>& checkExtensions);
	void createLogicalDevice();

	//physical device
	void getPhysicalDevice();
	bool checkDeviceSuitable(vk::PhysicalDevice device);
	QueueFamilyIndices getQueueFamilies(vk::PhysicalDevice device);
	
};