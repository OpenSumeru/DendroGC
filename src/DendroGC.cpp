#include "DendroGC.hpp"

namespace DendroGC
{

GC mainGC;

GC::GC()
{

}

GC::~GC()
{

}

bool GC::ClearMemory(std::thread::id id)
{
    for (auto& rax : varLists[id])
    {
        if (rax->count < 0)
        {
            delete rax->ptr; 
            rax->ptr = nullptr;
        }
    }
}

}