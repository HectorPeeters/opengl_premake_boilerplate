#include "window.h"

#include "gl_utils.h"

#include <stdio.h>

Window::Window(const char *title, unsigned int width, unsigned int height, bool vsync = true)
{
    m_Data = WindowData{
        title,
        width,
        height,
        vsync,
    };
}

Window::~Window()
{
}

bool Window::Create()
{
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to init GLFW\n");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    printf("GLFW version: %s\n", glfwGetVersionString());

    m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title, NULL, NULL);

    if (m_Window == NULL)
    {
        fprintf(stderr, "Failed to create GLFW window");
        return false;
    }

    glfwSetWindowUserPointer(m_Window, &m_Data);

    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
        WindowData *data = (WindowData *)glfwGetWindowUserPointer(window);
        data->width = width;
        data->height = height;
        GL(glViewport(0, 0, width, height));

        printf("Resized %d, %d\n", data->width, data->height);
    });

    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to init GLAD\n");
        return 1;
    }

    printf("OpenGL version: %s\n", glGetString(GL_VERSION));

    SetVsync(m_Data.vsync);

    return true;
}

void Window::Destroy()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Window::Update()
{
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(m_Window);
}

bool Window::IsVsync()
{
    return m_Data.vsync;
}

void Window::SetVsync(bool vsync)
{
    m_Data.vsync = vsync;
    glfwSwapInterval(vsync ? 1 : 0);
}

GLFWwindow *Window::GetGlfwWindow()
{
    return m_Window;
}

WindowData *Window::GetDataPointer()
{
    return &m_Data;
}

glm::ivec2 Window::GetSize()
{
    return {m_Data.width, m_Data.height};
}