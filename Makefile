CXX = g++
CXXFLAGS = -Wall -O3

SRCS = main.cpp evaluate.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = defs.hpp
TARGET = qualiflex

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

strip:
	strip $(TARGET)
