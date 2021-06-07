double_linked_list: double_linked_list.o main.o
	g++ -o double_linked_list double_linked_list.o main.o

double_linked_list.o: double_linked_list.cpp
	g++ -c double_linked_list.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o double_linked_list