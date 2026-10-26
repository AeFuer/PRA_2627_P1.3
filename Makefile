bin/testMonedas: test/testMonedas.cpp src/monedas.cpp include/monedas.h
	mkdir -p bin
	g++ -o bin/testMonedas test/testMonedas.cpp src/monedas.cpp -I include
