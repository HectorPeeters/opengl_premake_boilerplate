#pragma once

#include <map>
#include <string>
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

    void Uniform1f(std::string name, float value);
    void Uniform2f(std::string name, glm::vec2 &value);
    void Uniform3f(std::string name, glm::vec3 &value);
    void Uniform4f(std::string name, glm::vec4 &value);

    void Uniform1i(std::string name, int value);
    void Uniform2i(std::string name, glm::ivec2 &value);
    void Uniform3i(std::string name, glm::ivec3 &value);
    void Uniform4i(std::string name, glm::ivec4 &value);

    void UniformMat4(std::string name, glm::mat4 &value);

private:
    int m_ProgramId;

    std::map<std::string, int> m_Uniforms;

    std::string m_Name;
    const char *m_VertexPath, *m_FragmentPath;

    unsigned int CreateShader(const char *name, const char *source, unsigned int type);
};
