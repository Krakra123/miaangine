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
        static void SetAssetPath(const std::string& path);

        static unsigned int Load(const std::string& vertexFileDir, const std::string& fragmentFileDir);
        static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

    private:
        static std::string _assetPath;
    };
}

#endif