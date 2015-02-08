all: ./
	g++ -std=c++11 -c -g -fpermissive ./include/TinyExtender.h -lGL -lX 2> errors.txt
	
