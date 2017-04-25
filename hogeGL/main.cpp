#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "fl1ne.h"


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define WINDOW_TITLE "hogeGL"


double elapsed_time = 0.0;


int main(int argc, char const *argv[]){
    if(!glfwInit()){
        std::cerr << "[ERR] GLFW Initialization failed." << std::endl;
        return -1;
    }

    //Create window at center of display
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, 0, 0);
    glfwSetWindowPos(window, (vidmode->width - WINDOW_WIDTH) / 2, (vidmode->height - WINDOW_HEIGHT) / 2);

    if(!window){
        std::cerr << "[ERR] Window Creation failed." << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //Turn on Vsync with 1 frame
    glfwSwapInterval(1);


    //Register callbacks
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);


    //Initialize GLEW
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        std::cerr << "[ERR] GLEW Initialization failed." << std::endl;
        return -1;
    }


    glClearColor(0.204f, 0.596f, 0.859f, 1.0f);


    while(!glfwWindowShouldClose(window)){
        elapsed_time = glfwGetTime();

        std::cout << "[DBG] Elapsed Time : " << elapsed_time << std::endl;

        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

