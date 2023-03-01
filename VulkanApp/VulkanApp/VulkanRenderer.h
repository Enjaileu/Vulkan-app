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
	#ifdef NDEBUG
		static const bool enableValidationLayers = false;
	#else
		static const bool enableValidationLayers = true;
	#endif
		static const vector<const char*> validationLayers;

	VulkanRenderer();
	~VulkanRenderer();
	int init(GLFWwindow* windowP);
	void clean();

private:
	GLFWwindow* window;
	vk::Instance instance;
	vk::Queue graphicsQueue;

	vk::SurfaceKHR surface;
	vk::Queue presentationQueue;

	// instances
	void createInstance();
	bool checkInstanceExtensionSupport(const std::vector<const char*>& checkExtensions);

	//physical device
	void createLogicalDevice();
	void getPhysicalDevice();
	bool checkDeviceSuitable(vk::PhysicalDevice device);
	QueueFamilyIndices getQueueFamilies(vk::PhysicalDevice device);

	// validation extension
	bool checkValidationLayerSupport();
	bool checkDeviceExtensionSupport(vk::PhysicalDevice device);
	std::vector<const char*>getRequiredExtensions();

	// debug
	VkDebugUtilsMessengerEXT debugMessenger;
	void setupDebugMessenger();
	VkResult createDebugUtilsMessengerEXT(VkInstance instance,
		const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void destroyDebugUtilsMessengerEXT(VkInstance instance,
		VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	
	// surface
	vk::SurfaceKHR createSurface();
};