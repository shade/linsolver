build:
	g++ -std=c++11 main.cpp -o solver

debug:
	make build
	./solver