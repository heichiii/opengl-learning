#include "libs/includes/glad.h"
#include "libs/includes/glfw3.h"
#include <iostream>

#include "components/includes/utils.h"

int main()
{
    //init glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    //glad init
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    //view port
    glViewport(0, 0, 800, 600);
    //window size change
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



    //shader
    GLuint shaderProgram = glCreateProgram();   //glCreateProgram()需要在glfw初始化后调用
    prepareShader(shaderProgram);
    //points
    // 顶点数据：位置 + 颜色
    float vertices[] = {
        // 位置             // 颜色
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // 左下角，红色
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // 右下角，绿色
         0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f  // 顶部，蓝色
    };

    // 创建 VBO 和 VAO
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // 绑定 VAO
    glBindVertexArray(VAO);

    // 绑定 VBO 并上传数据
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 设置顶点属性指针(VAO更改)
    // 位置属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // 颜色属性
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);




    //render loop
    while(!glfwWindowShouldClose(window))
    {

        // 使用着色器程序
        glUseProgram(shaderProgram);

        // 绑定 VAO
        glBindVertexArray(VAO);

        // 绘制三角形
        glDrawArrays(GL_TRIANGLES, 0, 3);



        processInput(window);
        glfwSwapBuffers(window);
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    //release resource
    // 清理资源
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}














