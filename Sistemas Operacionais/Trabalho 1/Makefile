###################################################
#                                                 #
# Joao Victor Zarate Pereira Araújo               #
# Julio Huang									  #
# Trabalho 1                                      #
# Professor(a): Ronaldo Alves		              #
#                                                 #
###################################################
############### Makefile Trabalho 1 ###############
TARGET=programa.out
CXX=g++
CPPFLAGS=-Wall -pedantic -std=c++11 -g
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
all: $(OBJ)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f *.o