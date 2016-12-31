all: main

main: main.cpp BSM.o
	g++ main.cpp BSM.o -o main

BSM.o: BSM.cpp
	g++ -o BSM.o -c BSM.cpp

clean:
	rm main
	rm BSM.o
