all: ./
	g++ -std=c++11 -c -g -fpermissive ./source/TinyExtender.cpp -I./include/ -o bin/libTinyExtender.a -lGL -lX 2> errors.txt
	
