
RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g -fsanitize=leak -fno-omit-frame-pointer
INCLUDES = 
LDFLAGS =
LDPATH =

SOURCES = $(shell ls *.cpp)
PROGS = $(subst .cpp,,$(SOURCES))
#PROGS = $(SOURCES:%.cpp=%)

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

%: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)
