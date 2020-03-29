a.out: makinghtml.o swatches.o 
	g++ makinghtml.o swatches.o 
swatches.o: swatches.cc swatches.h
	g++ -c swatches.cc
makinghtml.o: makinghtml.cc swatches.h 
	g++ -c makinghtml.cc
clean: 
	rm -f *.o a.out