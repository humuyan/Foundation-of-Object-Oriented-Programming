main: main.o product.o sum.o
	g++ $^ -o $@ ${FLAG}
main.o: main.cpp functions.h
	g++ $< -c ${FLAG}
product.o: product.cpp functions.h
	g++ $< -c ${FLAG}
sum.o: sum.cpp functions.h
	g++ $< -c ${FLAG}
clean:
	rm *.o main
