all:
	g++ -std=c++17 -o particle-simulation ./src/*.cpp -pthread -lsfml-graphics -lsfml-window -lsfml-system -fopenmp
clean:
	rm -f $(OBJ) $(OUT)
