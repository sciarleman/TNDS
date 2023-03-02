esercizio2.1 : esercizio_2.1.o Vettore.o funzioni.o
	g++ esercizio_2.1.o Vettore.o funzioni.o -o esercizio2.1

esercizio_2.1.o : esercizio_2.1.cpp funzioni.h
	g++ -c esercizio_2.1.cpp -o esercizio_2.1.o

funzioni.o : funzioni.cpp funzioni.h
	g++ -c funzioni.cpp -o funzioni.o

Vettore.o : Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

clean : 

	rm -f *.o esercizio2.1

cleanall : clean

	rm esercizio2.1
