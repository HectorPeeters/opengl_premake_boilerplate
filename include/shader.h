#pragma once

#include <map>

#include <glm/glm.hpp>

class Shader
{
public:
    Shader(const char *name, const char *vertexPath, const char *fragmentPath);
    ~Shader();

    bool Create();
    void Destroy();

    void Bind();
    void Unbind();

    void Uniform1f(const char *name, float value);
    void Uniform2f(const char *name, glm::vec2 &value);
    void Uniform3f(const char *name, glm::vec3 &value);
    void Uniform4f(const char *name, glm::vec4 &value);

    void Uniform1i(const char *name, int value);
    void Uniform2i(const char *name, glm::ivec2 &value);
    void Uniform3i(const char *name, glm::ivec3 &value);
    void Uniform4i(const char *name, glm::ivec4 &value);

    void UniformMat4(const char *name, glm::mat4 &value);

private:
    int m_ProgramId;

    std::map<const char *, int> m_Uniforms;

    std::string m_Name;
    const char *m_VertexPath, *m_FragmentPath;

    unsigned int CreateShader(const char *name, const char *source, unsigned int type);
};
