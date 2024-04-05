
#include <atomic>
#include <deque>
#include <list>
#include <thread>
#include <unordered_map>

namespace DendroGC
{

struct PtrPackage
{
    void* ptr = nullptr;
    std::atomic_uint64_t count = 0;
};

class GC
{
private:
    std::unordered_map<std::thread::id, std::deque<PtrPackage*>> varLists;
    bool ClearMemory();
public:
    inline std::deque<PtrPackage*>& getListById()
    {
        return varLists[std::this_thread::get_id()];
    }
    GC();
    ~GC();
};

extern GC mainGC;

class ptr
{
private:
    PtrPackage* toPackage;
public:
    ptr() = delete;
    inline ptr(const ptr& input)
    {
        toPackage = input.toPackage;
        toPackage->count.fetch_add(1, std::memory_order_relaxed);
    }
    inline ptr(void* input)
    {
        thread_local std::deque<PtrPackage*>& varList = mainGC.getListById();
        toPackage = new PtrPackage;
        toPackage->ptr = input;
        toPackage->count.fetch_add(1, std::memory_order_relaxed);
        varList.push_back(toPackage);
    }
    inline ~ptr()
    {
        toPackage->count.fetch_sub(1, std::memory_order_relaxed);
    }
    template<typename T>
    inline T& get()
    {
        return *(T*)(toPackage->ptr);
    }
};

template<typename T>
class typePtr
{
private:
    PtrPackage* toPackage;
public:
    typePtr() = delete;
    inline typePtr(T* input)
    {
        thread_local std::deque<PtrPackage*>& varList = mainGC.getListById();
        toPackage = new PtrPackage;
        toPackage->ptr = input;
        toPackage->count.fetch_add(1, std::memory_order_relaxed);
        varList.push_back(toPackage);
    }
    inline typePtr(const typePtr<T>& input)
    {
        toPackage = input.toPackage;
        toPackage->count.fetch_add(1, std::memory_order_relaxed);
    }
    inline ~typePtr()
    {
        toPackage->count.fetch_sub(1, std::memory_order_relaxed);
    }
    inline T& operator->()
    {
        return *(T*)(toPackage->ptr);
    }
    inline T& operator*()
    {
        return *(T*)(toPackage->ptr);
    }
    inline T& get()
    {
        return *(T*)(toPackage->ptr);
    }
};

}