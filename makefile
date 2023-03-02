esercizio1.3 : esercizio1.3.cpp  funzioni.o
	g++  esercizio1.3.cpp -o esercizio1.3

funzioni.o : funzioni.cpp funzioni.h
	g++ -c funzioni.cpp -o funzioni.o

clean : esercizio1.3

	rm esercizio1.3
