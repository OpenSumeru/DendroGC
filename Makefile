CXX = clang++
CXXFLAG = -std=c++20

INCLUDEDIR = include
SRCDIR = src
OBJDIR = obj

RM = rm

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

FLAG = $(CXXFLAG) -I$(INCLUDEDIR)
LINK =
EXE = main

$(OBJS):$(SRCS)
	$(CXX) $(FLAG) -c $< -o $@

clean:
	$(RM) $(OBJS)

libobj: $(OBJS)


main: main.cpp $(OBJS)
	$(CXX) $(FLAG) $^ -o $(EXE) $(LINK)
