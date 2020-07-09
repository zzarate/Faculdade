###################################################
#                                                 #
# João Víctor Zárate Pereira Araújo               #
# Trabalho 2                                      #
# Professor(a): Diego Padilha Rubert              #
#                                                 #
###################################################
############### Makefile Trabalho 2 ###############
TARGET=programa.out
CXX=g++
CPPFLAGS=-Wall -pedantic -std=c++11 -g
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
all: $(OBJ)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJ)
	rm -f *.o