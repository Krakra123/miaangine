#ifndef _MIA_SHADER_H
#define _MIA_SHADER_H

#include <string>

namespace mia
{
    struct ShaderProgramSource
    {
        std::string vertexSource;
        std::string fragmentSource;
    };

    class Shader
    {
    public:
        Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
        ~Shader();

    public:
        void Bind() const;
        void Unbind() const;

        void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

    private:
        unsigned int _type;
        std::string _vertexPath;
        std::string _fragmentPath;

        unsigned int _shaderId;

    public:
        inline unsigned int GetType() const { return _type; }
        inline const std::string& GetVertexShaderPath() const { return _vertexPath; }
        inline const std::string& GetFragmentShaderPath() const { return _fragmentPath; }
        inline unsigned int GetShader() const { return _shaderId; }

    private:
        // bool CompileShader();
        unsigned int GetUniformLocation(const std::string& name) const;
    };
}

#endif