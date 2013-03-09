CC=g++
CFLAGS=-g 
all:	test simulation
test: test.o camera.o correlation.o util.o
	$(CC)	$(CFLAGS) test.o camera.o correlation.o util.o -o test
simulation: simulation.o camera.o correlation.o util.o
	$(CC)	$(CFLAGS) simulation.o camera.o correlation.o util.o -o simulation

test.o:	test.cpp camera.h correlation.h util.h 
	$(CC)	$(CFLAGS) -c test.cpp -o test.o
simulation.o: simulation.cpp camera.h correlation.h
	$(CC)	$(CFLAGS) -c simulation.cpp -o simulation.o
camera.o: camera.cpp camera.h
	$(CC) 	$(CFLAGS) -c camera.cpp -o camera.o
correlation.o: correlation.cpp camera.h correlation.h util.h
	$(CC) 	$(CFLAGS) -c correlation.cpp -o correlation.o
util.o: util.cpp util.h
	$(CC)	$(CFLAGS) -c util.cpp -o util.o
	
clean:
	rm -rf *.o test simulation
