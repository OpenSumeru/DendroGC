#pragma once

#include <DendroGC.share.hpp>
#include <DendroGC.container.hpp>

namespace DendroGC
{
    class VarList
    {
    private:
        const i64 capability;
        i64 nodeNum;
        Container*** objNodeList;
        ArrayContainer*** vecNodeList;
    public:
        VarList(i64 c = 64, i64 n = 64);
        void clearListNull();
    };

    
}