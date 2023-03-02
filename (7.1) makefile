LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio7.1 : esercizio_7.1.cpp FunzioneBase.h Seno.h Integral.h
	g++ esercizio_7.1.cpp -o esercizio7.1 ${INCS} ${LIBS}

clean: 
	rm esercizio7.1
