#pragma once
#include <DendroGC.share.hpp>

#include <atomic>

namespace DendroGC
{

    struct Container
    {
        std::atomic_int64_t count;
        void* pointer = nullptr;
        inline Container(void* p)
        {
            count = 0;
            pointer = p;
        }
        inline ~Container()
        {
            delete pointer;
        }
    };
    
    struct ArrayContainer
    {
        std::atomic_int64_t count;
        void* pointer = nullptr;
        inline ArrayContainer(void* p)
        {
            count = 0;
            pointer = p;
        }
        inline ~ArrayContainer()
        {
            delete[] pointer;
        }
    };
}