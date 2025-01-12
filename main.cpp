#include "TRIE.h"
#include <iostream>
#include <vector>

void imprimirArr(std::vector<std::string> arr){
	for(const auto& i: arr){
		std::cout << i  << std::endl;
	}
}

int main(){
    TRIE arbol2;
    
    arbol2.rellenarArbol("PERRO");
    arbol2.rellenarArbol("GATO");
    arbol2.rellenarArbol("GATA");
    arbol2.rellenarArbol("PAJARO");
    arbol2.rellenarArbol("ANIMAL");
    arbol2.rellenarArbol("PITON");
    arbol2.rellenarArbol("PISCINA");
    arbol2.rellenarArbol("CASA");
    arbol2.rellenarArbol("MUEBLE");
	
	std::vector<std::string> test = arbol2.autocompletado("C");
	
	imprimirArr(test);
    
	return 0;
}


