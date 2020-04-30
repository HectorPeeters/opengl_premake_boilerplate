#pragma once

#include "engine.h"

struct WindowData
{
    const char *title;
    unsigned int width, height;
    bool vsync;
};

class Window
{
public:
    Window(const char *title, unsigned int width, unsigned int height, bool vsync);
    ~Window();

    bool Create();
    void Destroy();

    void Update();

    bool ShouldClose();

    bool IsVsync();
    void SetVsync(bool vsync);

    GLFWwindow *GetGlfwWindow();

    glm::ivec2 GetSize();

private:
    GLFWwindow *m_Window;
    WindowData m_Data;
};