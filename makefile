In questa lezione impareremo a costruire un generatore di numeri casuali. Lo utilizzeremo quindi per generare numeri secondo una distribuzione uniforme, esponenziale e Gaussiana. Come applicazione utilizzeremo la generazione di numeri casuali per calcolare numericamente integrali mono e multi-dimensionali.

ESERCIZIO 10.0 - Generatore di numeri casuali (da consegnare):

Scrivere un programma che produca quattro istogrammi contenenti ciascuno 10000 numeri pseudo-casuali estratti da :
una distribuzione uniforme tra 5 e 10.
una distribuzione esponenziale tra 0 e + ∞ con costante k=1.
una distribuzione gaussiana centrata in 1 e larghezza 1 con il metodo di Box-Muller.
una distribuzione gaussiana centrata in 1 e larghezza 1 con il metodo accept-reject.
Per risolvere questo esercizio si può seguire lo schema seguente:
Scrivere una classe opportuna per la generazione di numeri casuali. La classe dovrà contenere un metodo che implementi un generatore lineare congruenziale di base e tutti i metodi necessari per le distribuzioni richieste.

Header file della classe RandomGen:

Il costruttore si farà carico di inizializzare i parametri del generatore ai valori m_a = 1664525, m_c = 1013904223 e m_m = 231.

Preparare un semplice main per provare le funzionalità della classe RandomGen.

------------------------------------------------------------------------------------------------------------------------

ESERCIZIO 10.2 - Calcolo di integrali con metodi MonteCarlo (da consegnare):
Calcolare 10000 volte il valore dell'integrale di sin(x) tra [0,π] utilizzando il metodo della media a 100 punti e fare un grafico ( istogramma ) della distribuzione dei valori ottenuti.
Estendere il punto precedente calcolando 10000 volte il valore dell'integrale di sin(x) tra [0,π] utilizzando il metodo della media a N punti con N pari a 100, 500, 1000, 5000, 10000 punti. Per ogni valore di N produrre il grafico della distribuzione dei 10000 valori ottenuti. [NOTA: poichè il calcolo degli integrali con N molto elevato potrebbe richiedere un certo tempo, potrebbe essere utile salvare in diversi files i valori degli integrali calcolati per un determinato N e svolgere i punti successivi con un secondo programma che utilizzi come input i files di integrali del programma precedente.]
Stimare l'errore sul calcolo dell'integrale a 100, 500, 1000, 5000, 10000 punti come deviazione standard dei 10000 valori calcolati per ogni N. Far un grafico di questo errore in funzione di N.
Assumendo che l'andamento dell'errore sia noto ( del tipo k/ √N ) si determini quanti punti sono necessari per ottenere una precisione di 0.001. Si ripeta lo stesso lavoro con il metodo hit-or-miss.


Per il calcolo di integrali con metodi MonteCarlo si può decidere di scrivere una nuova classe dedicata o estendere la classe Integral della lezione 8. In ogni caso ci dovrà essere un puntatore ad un oggetto di tipo RandomGen e due metodi che implementino le due tecniche discusse. 
