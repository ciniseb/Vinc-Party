main.exe: main.o SerialPort.o ES.o
	g++ -o main.exe main.o SerialPort.o ES.o

main.o: main.cpp ./include/json.hpp ./include/serial/SerialPort.hpp
	g++ -g -c main.cpp

SerialPort.o: ./include/serial/SerialPort.hpp
	g++ -g -c ./include/serial/SerialPort.cpp

ES.o: ES.h ES.cpp
	g++ -g -c ES.cpp