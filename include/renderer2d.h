#pragma once

#include "engine.h"
#include "shader.h"
#include "window.h"

#define DEFAULT_MAX_BATCH_QUAD_COUNT 100 * 100

struct Renderer2DVertexData
{
    glm::vec3 position;
    glm::vec4 color;
};

struct Renderer2DBatch
{
    unsigned int vao;
    unsigned int vbo;
    unsigned int ibo;

    unsigned int vertex_count = 0;

    unsigned int texture_id = 0;

    Renderer2DVertexData *vertex_data;
    Renderer2DVertexData *vertex_data_pointer = vertex_data;
};

class Renderer2D
{
public:
    Renderer2D(Shader &shader, WindowData *windowData, int maxBatchQuadCount = DEFAULT_MAX_BATCH_QUAD_COUNT);
    ~Renderer2D();

    bool Create();
    void Destroy();

    void Start();
    void End();

    void DrawQuad(glm::vec2 position, glm::vec2 scale, glm::vec4 color);

    void DrawImGui();

private:
    Shader &m_Shader;

    glm::mat4 m_ProjectionMatrix;
    glm::mat4 m_ViewMatrix;

    WindowData *m_WindowData;

    const int m_MaxBatchVertexCount;

    int m_TotalBatchCount;
    int m_TotalVertexCount;

    unsigned int m_Vao;
    unsigned int m_Vbo;
    unsigned int m_Ibo;
    unsigned int m_VertexCount;

    Renderer2DVertexData *m_VertexData;
    Renderer2DVertexData *m_VertexDataPointer;

    void DrawBatch();
};