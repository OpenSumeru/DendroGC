# DendroGC
Simple C++ garbage collector

## Notice

This project has met some problems on algorithm. We think we need more study, and we will rebuild this project then.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Build](#build)
4. [Dependece](#dedependence)
5. [License](#license)

## Introduction

DendroGC is an improvement over shared_ptr, aiming to more effectively manage memory using garbage collection techniques.

## Usage

Include the include filter in your project and link share library libDendroGC.

### Simple example
```C++
#include <DendroGC>

DendroGC::GC mainGC; //Very important! You should always include this in your code to make sure DendroGC can be running.

int main()
{
    
    return 0;
}
```

## Build
run

```bash
make libDendroGC
```

## Dedependence
- std C++ 20 or higher

## LICENSE
MIT License.
