OPTIONS = -O2 -Wall -Wextra -pedantic -ansi -DNDEBUG
LIBS = -ldnest3 -lgsl -lgslcblas -lboost_thread-mt -lboost_system

default:
	g++ $(OPTIONS) -c *.cpp
	g++ -o main *.o $(LIBS)
	rm -f main.o
	rm -f *.o

