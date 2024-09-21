#ifndef _MIA_SHADER_UTIL_H
#define _MIA_SHADER_UTIL_H

#include <cstdint>
#include <string>

namespace mia
{
    class ShaderUtil
    {
    public:
        ShaderUtil();
        ~ShaderUtil();

    public:
        bool Load(const std::string& vertexSource, const std::string& fragmentSource);
        void Use();
        void Delete();

    private:
        unsigned int _programID;

        unsigned int GetCompiledShader(unsigned int type, const std::string& source);
        std::string ReadFile(const std::string& source);
    };
}

#endif