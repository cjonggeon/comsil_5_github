cc=g++

main : main.o
	g++ -o main main.o

main.o : main.cpp LinkedList.h
	g++ -c -o main.o main.cpp

.PHONY : clean
clean : 
	rm *.o main
