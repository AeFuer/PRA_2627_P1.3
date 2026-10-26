bin/testMonedas: test/testMonedas.cpp src/monedas.cpp include/monedas.h
	mkdir -p bin
	g++ -o bin/testMonedas test/testMonedas.cpp src/monedas.cpp -I include

bin/testKnapsack: test/testKnapsack.cpp src/knapsack.cpp include include/knapsack.h
	mkdir -p bin
	g++ -o bin/testKnapsack test/testKnapsack.cpp src/knapsack.cpp -I include
