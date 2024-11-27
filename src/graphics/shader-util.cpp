#include "graphics/shader-util.hpp"

#include <GL/glew.h>
#include <iostream>
#include <fstream>

#include "core/debug/log-system.hpp"

namespace mia
{
    unsigned int CompileShader(unsigned int type, const std::string& source);
    //

    std::string ShaderUtil::_assetPath;

    ShaderUtil::ShaderUtil() = default;
    ShaderUtil::~ShaderUtil() = default;

    void ShaderUtil::SetAssetPath(const std::string& path)
    {
        _assetPath = path;
    }

    unsigned int ShaderUtil::Load(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
    {
        return CreateShader(ReadFile(vertexShaderPath), ReadFile(fragmentShaderPath));
    }

    unsigned int ShaderUtil::CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
    {
        unsigned int program = glCreateProgram();

        unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
        unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

        glValidateProgram(program);

        glAttachShader(program, fs);
        glAttachShader(program, vs);

        glLinkProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);

        return program;
    }

    std::string ShaderUtil::ReadFile(const std::string& path)
    {
        std::ifstream is(path);

        if (!is.is_open()) {
            is = std::ifstream(_assetPath + '/' + path);

            if (!is.is_open()) {
                mia::LogManager::LogError("Undefined path: %s", path.c_str());
            }
        }

        std::istreambuf_iterator<char> begin(is);
        std::istreambuf_iterator<char> end;
        return std::string(begin, end);
    }

    unsigned int CompileShader(unsigned int type, const std::string& source)
    {
        unsigned int id = glCreateShader(type);

        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        GLint res = -1;
        glGetShaderiv(id, GL_COMPILE_STATUS, &res);

        if (res == GL_FALSE) {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

            GLchar* infoLog = new GLchar[length + 1];
            glGetShaderInfoLog(id, length, &length, infoLog);

            mia::LogManager::LogError("Compilation error in shader:\n%s", infoLog);
            delete[] infoLog;
        }

        return id;
    }
}