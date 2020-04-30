#include <stdio.h>

#include "engine.h"
#include "shader.h"
#include "gl_utils.h"

int main()
{
    glm::vec3 vector(1, 0, 1);
    printf("%f %f %f\n", vector.x, vector.y, vector.z);

    if (!glfwInit())
    {
        fprintf(stderr, "Failed to init GLFW\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    glfwSwapInterval(1);

    // Setup model

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    unsigned int vao;
    GL(glGenVertexArrays(1, &vao));
    GL(glBindVertexArray(vao));
    unsigned int vbo;
    GL(glGenBuffers(1, &vbo));
    GL(glBindBuffer(GL_ARRAY_BUFFER, vbo));
    GL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));

    GL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));
    GL(glEnableVertexAttribArray(0));

    Shader shader("Basic");
    if (!shader.Create("res/basic.vert", "res/basic.frag"))
        return 1;

    // Setup ImGui

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    bool show_demo_window = true;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        shader.Bind();
        GL(glBindVertexArray(vao));
        GL(glDrawArrays(GL_TRIANGLES, 0, 3));
        shader.Unbind();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    shader.Delete();

    glfwTerminate();
}