linked_list: linked_list.o main.o
	g++ -o linked_list linked_list.o main.o

linked_list.o: linked_list.cpp
	g++ -c linked_list.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *o linked_list