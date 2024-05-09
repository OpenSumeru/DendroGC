#include "DendroGC.ptr.hpp"
#include <iostream>
#include <malloc.h>
#include <thread>
#include <type_traits>
#include <vector>
#include <memory>
#include <DendroGC.hpp>
using namespace std;

int main()
{
    cout << sizeof(DendroGC::ObjPtr<int>) << endl;
    cout << sizeof(DendroGC::VecPtr<int>) << endl;
    
    return 0;
}