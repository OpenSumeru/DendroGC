#include "DendroGC.list.hpp"
#include "DendroGC.container.hpp"

namespace DendroGC
{
    VarList::VarList(i64 c, i64 n) : capability(c)
    {
        objNodeList = new Container**[n];
        vecNodeList = new ArrayContainer**[n];
        for (i64 i = 0; i < n; i++) 
        {
            objNodeList[i] = new Container*[c];
            vecNodeList[i] = new ArrayContainer*[c];
            for (i64 j = 0; j < c; j++)
            {
                objNodeList[i][j] = nullptr;
                vecNodeList[i][j] = nullptr;
            }
        }
    }

    void VarList::clearListNull()
    {
        for (i64 i = 0; i < nodeNum; i++)
        {
            for (i64 j = 0; j < capability; j++)
            {
                
            }
        }
    }
}