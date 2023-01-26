main.exe: main.o SerialPort.o
	g++ -o main.exe main.o SerialPort.o

main.o: main.cpp ./include/json.hpp ./include/serial/SerialPort.hpp
	g++ -g -c main.cpp

SerialPort.o: ./include/serial/SerialPort.hpp
	g++ -g -c ./include/serial/SerialPort.cpp