# target : dependencies
#		action
# MAC = clang++ | Linux = g++ 

CXX = g++
CC = gcc
CFLAGS += -g -Wall -c -std=c++17
LFLAGS += -Wall 
#Libraray link
LDFLAGS += -lc

TARGET = Permutation

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
# $(patsubst pattern,replacement,text)
INCL_DIR = include/


#.cpp.o -> I will use .cpp file for .o file
# .조건.확장자 = %.o : %.cpp 
# replaces blew
.cpp.o : 
	$(CXX) $(CFLAGS) $<
#things.o : things.cpp things.h
#	$(CXX) $(CFLAGS) $<
#	g++ -c -Wall things.cpp

## Replaces right below
$(TARGET) : ${OBJS}
	$(CXX) $(LFLAGS) $^ ${LDFLAGS} -o build/$@
	rm -f *.o
#maketest : maketest.o apples.o things.o
#	g++ maketest.o apples.o things.o -o maketest
#  $@  -> name of target 
#  $^  -> name of all the prerequisits.   $^ = $(OBJS) = maketest.o things.o apples.o

clean :
	rm -rf build/* && rm -f *.o $(TARGET) 

tar:
	tar -cfv $(TARGET).tar $(TARGET) *.cpp *.h

