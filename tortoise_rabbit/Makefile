xx = g++

program: move.o print.o main.o	
	$(xx) -o program main.o print.o move.o

main.o: main.cpp print.h move.h
	$(xx) -c main.cpp

move.o: move.cpp move.h 
	$(xx) -c move.cpp

print.o: print.cpp print.h
	$(xx) -c print.cpp

clean:
	del -f program main.o move.o print.o