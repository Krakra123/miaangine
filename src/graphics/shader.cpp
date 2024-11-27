#include "graphics/shader.hpp"

#include <GL/glew.h>
#include "graphics/shader-util.hpp"

namespace mia
{
    unsigned int CompileShader(unsigned int type, const std::string& source);

    Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath):
        _vertexPath(vertexShaderPath), _fragmentPath(fragmentShaderPath)
    {
        _shaderId = mia::ShaderUtil::Load(vertexShaderPath, fragmentShaderPath);
    }

    Shader::~Shader()
    {
        glDeleteProgram(_shaderId);
    }

    void Shader::Bind() const
    {
        glUseProgram(_shaderId);
    }

    void Shader::Unbind() const 
    {
        glUseProgram(0);
    }

    void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3) 
    {
        int location = glGetUniformLocation(_shaderId, name.c_str());
        glUniform4f(location, v0, v1, v2, v3);
    }
}