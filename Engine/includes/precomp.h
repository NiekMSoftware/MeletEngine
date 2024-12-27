#pragma once

// std
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>

#include <print>
#include <format>

// common
#include <string>
#include <vector>

// this is hideous, optional
using namespace std;

// vulkan
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// engine
#include "VePipeline.h"
#include "VeWindow.h"

// applications
#include "FirstApp.h"