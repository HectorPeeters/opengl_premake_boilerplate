#include <stdio.h>

#include "engine.h"

int main()
{

    glm::vec3 vector(1, 0, 1);
    printf("%f %f %f\n", vector.x, vector.y, vector.z);

    if (!glfwInit())
    {
        fprintf(stderr, "Failed to init GLFW\n");
        return 1;
    }

    printf("GLFW version: %s\n", glfwGetVersionString());

    GLFWwindow *window = glfwCreateWindow(500, 300, "Window Title", NULL, NULL);

    if (window == NULL)
    {
        fprintf(stderr, "Failed to create GLFW window");
        return 1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to init GLAD\n");
        return 1;
    }

    printf("OpenGL version: %s\n", glGetString(GL_VERSION));

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}