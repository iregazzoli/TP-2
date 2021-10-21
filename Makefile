FLAGS = -Wall -Werror -Wconversion

main: main.o city.o building.o
		g++ main.o city.o building.o $(FLAGS) -o main

main.o: main.cpp
	g++ -c main.cpp

city.o: city.cpp
	g++ -c city.cpp

building.o: building.cpp
	g++ -c building.cpp

clean:
	rm *.o main
