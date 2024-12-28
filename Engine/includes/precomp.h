#pragma once

// std io
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <print>
#include <format>
#include <assert.h>

// containers
#include <string>
#include <vector>
#include <array>
#include <set>
#include <unordered_set>

// memory
#include <memory>

// this is hideous, optional
using namespace std;

// vulkan
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

// engine
#include "VePipeline.h"
#include "VeSwapChain.h"
#include "VeWindow.h"
#include "VeDevice.h"

#include "VeModel.h"

// applications
#include "FirstApp.h"