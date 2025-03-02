//
// Created by GaoKailong on 25-2-28.
//

#ifndef UTILS_H
#define UTILS_H
#include "../../libs/includes/glad.h"
#include "../../libs/includes/glfw3.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void prepareShader(GLuint & shaderProgram);

#endif //UTILS_H
