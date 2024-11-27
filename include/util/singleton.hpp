#ifndef _MIA_SINGLETON_HPP
#define _MIA_SINGLETON_HPP

#include <memory>

namespace mia
{
    template <typename T> 
    class Singleton
    {
    protected:
        Singleton() = default;

        static std::unique_ptr<T> _instance;

    public:
        Singleton(Singleton const &) = delete;
        Singleton& operator=(Singleton const &) = delete;
    
        static T& Instance() {
            return *_instance;
        }
    };

    template <typename T>
    std::unique_ptr<T> Singleton<T>::_instance = std::make_unique<T>();
}

#endif