#pragma once
#include <vector>
using std::vector;

struct QueueFamilyIndices
{
	int graphicsFamily = -1; // Location of Graphics Queue Family
	int presentationFamily = -1; 

	bool isValid()
	{
		return graphicsFamily >= 0;
	}
};

const vector<const char*> deviceExtensions
{
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};