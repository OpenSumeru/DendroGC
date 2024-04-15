CXX = clang++
CXXFLAG = -std=c++20
PCHFLAG = -x c++-header

RM = rm

INCLUDEDIR = include
SRCDIR = src

HEADERPPS = $(wildcard $(INCLUDEDIR)/*.hpp) 
HEADERS = $(wildcard $(INCLUDEDIR)/*.h)
PCHS = $(patsubst $(INCLUDEDIR)/%.hpp,$(INCLUDEDIR)/%.pch,$(HEADERPPS)) \
       $(patsubst $(INCLUDEDIR)/%.h,$(INCLUDEDIR)/%.pch,$(HEADERS))

SRCPPS = $(wildcard $(SRCDIR)/*.cpp)
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(SRCDIR)/%.o,$(SRCPPS)) \
       $(patsubst $(SRCDIR)/%.c,$(SRCDIR)/%.o,$(SRCS))

FLAG = $(CXXFLAG) -I$(INCLUDEDIR)
LINK =

LIB = libDendroGC.dll
EXELINK = -L . -lDendroGC
EXE = main.exe

%.pch: %.h
	$(CXX) $(PCHFLAG) $(FLAG) $< -o $@ -Winvalid-pch

%.pch: %.hpp
	$(CXX) $(PCHFLAG) $(FLAG) $< -o $@ -Winvalid-pch

%.o: %.cpp
	$(CXX) $(FLAG) -I $(INCLUDEDIR) -c $< -o $@

%.o: %.cpp
	$(CXX) $(FLAG) -I $(INCLUDEDIR) -c $< -o $@

libDendroGC: $(PCHS) $(OBJS)
	$(CXX) $(FLAG) -shared $(OBJS) -o $(LIB) $(LINK)

main: main.cpp
	$(MAKE) libDendroGC
	$(CXX) $(FLAG) main.cpp $(OBJS) -o $(EXE) $(EXELINK)

clean:
	- $(RM) $(OBJS)
	- $(RM) $(PCHS)
	- $(RM) main.o

clear:
	- $(MAKE) clean
	- $(RM) $(EXE)
