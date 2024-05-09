#pragma once
#include <DendroGC.share.hpp>
#include <DendroGC.container.hpp>

namespace DendroGC
{
    template<typename objType>
    class ObjPtr
    {
    private:
        Container* obj = nullptr;
    public:

        ObjPtr() = delete;
        inline ObjPtr(Container* input)
        {
            obj = input;
        }
        inline ObjPtr(const ObjPtr& input)
        {
            obj = input.obj;
            obj->count.fetch_add(1);
        }
        inline ~ObjPtr()
        {
            obj->count.fetch_sub(1);
        }
        inline operator objType&()
        {
            return (objType*)(obj->pointer);
        }
        inline objType* getPtr()
        {
            return obj->pointer;
        }
        inline objType& get()
        {
            return (objType*)(obj->pointer);
        }
    };
    
    template<typename vecType>
    class VecPtr
    {
    private:
        ArrayContainer* vec = nullptr;
    public:

        VecPtr() = delete;
        inline VecPtr(ArrayContainer* input)
        {
            vec = input;
        }
        inline VecPtr(const VecPtr& input)
        {
            vec = input.vec;
            vec->count.fetch_add(1);
        }
        inline ~VecPtr()
        {
            vec->count.fetch_sub(1);
        }
        inline vecType& operator[](i64 index)
        {
            return ((vecType*)(vec->pointer))[index];
        }
        inline vecType* getPtr()
        {
            return vec->pointer;
        }
    };

}