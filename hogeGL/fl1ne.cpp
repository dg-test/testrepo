#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "fl1ne.h"


void errorCallback(int error, const char* description){
    std::cerr << "[ERR] " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}