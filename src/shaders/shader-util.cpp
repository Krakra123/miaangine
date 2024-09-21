#include "shader-util.h"

#include <GL/glew.h>
#include <iostream>
#include <fstream>

#include "debug/log-system.h"

namespace mia
{
    ShaderUtil::ShaderUtil() = default;
    ShaderUtil::~ShaderUtil() = default;

    bool ShaderUtil::Load(const std::string& vertexSource, const std::string& fragmentSource)
    {
        const std::string fVs = ReadFile(vertexSource);
        const std::string fFs = ReadFile(fragmentSource);

        _programID = glCreateProgram();

        unsigned int vs = GetCompiledShader(GL_VERTEX_SHADER, fVs);
        unsigned int fs = GetCompiledShader(GL_VERTEX_SHADER, fFs);

        glAttachShader(_programID, vs);
        glAttachShader(_programID, fs);

        glLinkProgram(_programID);
        glValidateProgram(_programID);

        glDeleteShader(vs);
        glDeleteShader(fs);

        return true;
    }

    void ShaderUtil::Use()
    {
        glUseProgram(_programID);
    }
    void ShaderUtil::Delete()
    {
        glDeleteProgram(_programID);
    }

    unsigned int ShaderUtil::GetCompiledShader(unsigned int type, const std::string& source)
    {
        unsigned int id = glCreateShader(type);

        const char* cSource = source.c_str();
        glShaderSource(id, 1, &cSource, nullptr);
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

    std::string ShaderUtil::ReadFile(const std::string& source)
    {
        std::ifstream is(source);
        std::istreambuf_iterator<char> begin(is);
        std::istreambuf_iterator<char> end;
        return std::string(begin, end);

    }
}