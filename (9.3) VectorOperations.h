#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>  // se se vogliono usare algoritmi STL
#include <numeric>    // per inner_product

using namespace std;

// somma ad a un vettore b e il risultato viene messo in a

template <typename T> vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
	
  // below different ways to check if vectors have the same size                                                                                                             
 	//controllo se vettori sono uguali
  // assert(a.size() == b.size());
  // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;                                                                                         
  if ( a.size() != b.size() ) {
    cout << "Trying to sum vectors with different size, exiting" << endl ;
    exit(-1);
  } ;
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) a[i] += b[i];    
  
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //    transform(a.begin(), a.end(), b.begin(), a.begin() , plus<T>()); 
  
  return a;
}

// sottrai ad a un vettore b e il risultato viene messo in a

template <typename T> vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  
  // below different ways to check if vectors have the same size                                                                                                             
  //controllo se vettori sono uguali
  // assert(a.size() == b.size());
  // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;                                                                                         
  if ( a.size() != b.size() ) {
    cout << "Trying to sum vectors with different size, exiting" << endl ;
    exit(-1);
  } ;
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) a[i] -= b[i];    
  
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //    transform(a.begin(), a.end(), b.begin(), a.begin() , minus<T>()); 
  
  return a;
}

// Possiamo usare funzioni generiche che agiscono sui vettori

  
// somma di due vettori componente per componente
                                                                                            
template <typename T> vector<T> operator+(const vector<T> &a, const vector<T> &b) {

	//controllo se vettori sono uguali
  // assert(a.size() == b.size());  
  //  if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;  
  if ( a.size() != b.size() ) { 
    cout << "Trying to sum vectors with different size, exiting" << endl ; 
    exit(-1); 
  } ; 
  
  vector<T> result(a.size());
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) {
		result[i] = a[i] + b[i];    
	}
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //  transform(a.begin(), a.end(), b.begin(), result.begin() , plus<T>()); 
  
  return result;
  
}

// differenza di due vettori componente per componente
// [ preferisco re-implementarlo perche' si fanno meno operazioni rispetto result = a + (-1.*b) ]

template <typename T> vector<T> operator-(const vector<T> &a, const vector<T> &b) {
  
  //controllo se vettori sono uguali
  // assert(a.size() == b.size());                                    
  // if ( a.size() != b.size() ) {throw "Trying to sum vectors with different size" };                                                                                             
  if ( a.size() != b.size() ) {
    cout << "Trying to sum vectors with different size, exiting" << endl ;
    exit(-1);
  } ;

  vector<T> result(a.size());
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) {
		result[i] = a[i] - b[i];    
	}
	
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //    transform(a.begin(), a.end(), b.begin(), result.begin() , minus<T>()); 
  
  return result;
  
}

// prodotto scalare tra due vettori 

template <typename T> T operator*(const vector<T> &a, const vector<T> &b) {

  // below different ways to check if vectors have the same size                                                                                                             
 	//controllo se vettori sono uguali
  // assert(a.size() == b.size());
  // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;                                                                                         
  if ( a.size() != b.size() ) {
    cout << "Trying to sum vectors with different size, exiting" << endl ;
    exit(-1);
  } ;

  T sum ;
  for (int i = 0; i < static_cast<int>(a.size()); i++) sum += a[i] * b[i];  
  
  // Alternativamente si puo' usare l'algoritmo inner_product della STL
  // sum = inner_product(begin(a), end(a), begin(b), 1.0);
  
  return sum;
  
}

// prodotto tra uno scalare e un vettore

template <typename T> vector<T> operator*( T c , const vector<T> &a) {
  
  vector<T> result(a.size());
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = c * a[i];  
  
  // Alternativamente si puo' usare l'algoritmo inner product
  //     transform(begin(a), end(a), begin(result), [&c](T x){ return x * c; } );
  
  return result;
  
}

// prodotto tra un vettore e uno scalare 

template <typename T> vector<T> operator*( const vector<T> &a , T c) {
  
  vector<T> result(a.size());
  
for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = c * a[i];  
  
  // oppure il ciclo for puo' essere sostituito da ( ~ stesso numero di operazioni con il
  // move constructor del vector altrimenti sarebbe meno efficiente )
  // 
  // result = c * a ;
  
  // Alternativamente si puo' usare l'algoritmo transform della STL con una lambda function
  //    
  //    transform(begin(a), end(a), begin(result), [&c](T x){ return x * c; } );
  
  return result;
  
}

// divisione tra un vettore e uno scalare 

template <typename T> vector<T> operator/( const vector<T> &a , T c) {
  
  vector<T> result(a.size());
  for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = a[i] / c ;  
  
  // oppure il ciclo for puo' essere sostituito da
  
  // double fact = 1./c
  // result = a * fact ;
  
  // Alternativamente si puo' usare l'algoritmo transform della STL con una lambda function
  //    
  //    transform(begin(a), end(a), begin(result), [&c](T x){ return x / c; } );
  
  return result;
  
}


  // metodo comodo per stampare il vettore
  
template <typename T> void Print( const vector<T> &v ) {
  
 // cout << "Printing vector" << endl;
  for ( auto it = v.begin() ; it != v.end() ; it++ ) cout << *it << " " ;
  cout << endl;
 // cout << "End of printing vector" << endl;
  
};

/*
template <typename T> class linearVector : public vector<T> {
  
public :

  linearVector<T> ( ) : vector<T>(){} ;
  linearVector<T> ( int size ) : vector<T>(size){} ;  

  linearVector<T> operator+( const linearVector<T> &a ) {
    
    assert(a.size() == this->size());
    
    linearVector<T> result(a.size()) ;
    for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = a[i] + (*this)[i];
    
    return result;
    
  }
  
};
*/
