output: main.o LinkedList.o HashMap.o
	g++ main.o LinkedList.o HashMap.o -o a.out

main.o: main.cpp
	g++ -c main.cpp
	
LinkedList.o: LinkedList.cpp LinkedList.hpp
	g++ -c LinkedList.cpp

HashMap.o: HashMap.cpp HashMap.hpp
	g++ -c HashMap.cpp

clean:
	rm *.o a.out
