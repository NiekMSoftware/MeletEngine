#pragma once

// std
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <assert.h>

#include <print>
#include <format>

// common
#include <string>
#include <vector>

#include <set>
#include <unordered_set>

// this is hideous, optional
using namespace std;

// vulkan
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// engine
#include "VePipeline.h"
#include "VeWindow.h"
#include "VeDevice.h"

// applications
#include "FirstApp.h"