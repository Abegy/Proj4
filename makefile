a.out: main.o swatches.o 
	g++ main.o swatches.o 
swatches.o: swatches.cc swatches.h
	g++ -c swatches.cc
main.o: main.cc swatches.h dlist.h
	g++ -c main.cc
clean: 
	rm -f *.o a.out