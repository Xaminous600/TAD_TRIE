#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <vector>
#include <algorithm>
class nodo{
    public:
        nodo* padre;
		nodo* hijoIzq;
		nodo* hermanoDer;
        char el;
        
        nodo(const char& el_, nodo* padre_ = nullptr) : el(el_), padre(padre_), hijoIzq(nullptr), hermanoDer(nullptr){}
};

class TRIE{
    public:
        TRIE(): raiz(new nodo('-')){}
                
        void insertarHijoIzq(nodo* n, char el);
        void insertarHermDer(nodo* n, char el);
        
        nodo* nodoRaiz() const;
        nodo* hijoIzq (nodo* n) const;
        nodo* hermDer (nodo* n) const;
        
        bool arbolVacio() const;
        
        void rellenarArbol(const std::string&); //Rellena el árbol dado un string
        void rellenarArbolRec(nodo* n, const std::string&, int& strLength);
        nodo* buscarNodo(nodo* n, char el);
        bool nodoHoja(nodo* n);
        
        std::vector<std::string> autocompletado(std::string);
        std::vector<std::string> recuperarSufijos(nodo* n, const std::string& prefijo);
        
        friend std::ostream& operator<<(std::ostream& os, const TRIE& arbol);
        void imprimirPreorden(std::ostream& os, nodo*) const;
        
    private:
        nodo* raiz;
};

void TRIE::insertarHijoIzq(nodo* n, char el){
	if(n != nullptr){
		nodo* hijoIzq = n->hijoIzq;
		
		n->hijoIzq = new nodo(el, n);
		
		n->hijoIzq->hermanoDer = hijoIzq;
	}
}

void TRIE::insertarHermDer(nodo* n, char el){
	if(n!= nullptr && n != this->raiz){
		nodo* hermDer = n->hermanoDer;
		
		n->hermanoDer = new nodo(el, n->padre);
		
		n->hermanoDer->hermanoDer = hermDer;
	}
}

nodo* TRIE::nodoRaiz() const{
	return this->raiz;
}

nodo* TRIE::hijoIzq(nodo* n) const{
	return n->hijoIzq;
}

nodo* TRIE::hermDer(nodo* n) const{
	return n->hermanoDer;
}

bool TRIE::arbolVacio() const {
	return this->raiz == nullptr;
}

void TRIE::rellenarArbol(const std::string& str){
	int strLength = 0;
	if(this->arbolVacio()){
		this->raiz = new nodo('-');
	}
	
	rellenarArbolRec(this->raiz, str, strLength);
}

void TRIE::rellenarArbolRec(nodo* n, const std::string& str, int& strLength){
	if(n != nullptr && strLength < str.length()){
	
		nodo* nHijo = buscarNodo(n, str[strLength]);
		
		if(nHijo == nullptr){
			this->insertarHijoIzq(n, str[strLength]);
			rellenarArbolRec(this->hijoIzq(n), str,strLength=strLength+1);
		}
		else{
			rellenarArbolRec(nHijo, str, strLength=strLength+1);
		}
	}
}

nodo* TRIE::buscarNodo(nodo* n, char el){
	nodo* nodoBuscar = nullptr;
	
	if(!this->nodoHoja(n)){	
		nodo* hijo = this->hijoIzq(n);
		
		while(hijo != nullptr){
			if(hijo->el == el){
				return hijo;
			}
			else{
				hijo = this->hermDer(hijo);
			}
		}	
	}
	
	return nodoBuscar;
}

bool TRIE::nodoHoja(nodo* n){
	return this->hijoIzq(n) == nullptr;
}

std::ostream& operator<<(std::ostream& os, const TRIE& arbol) {
	arbol.imprimirPreorden(os, arbol.nodoRaiz());
    return os;
}

void TRIE::imprimirPreorden(std::ostream& os, nodo* n) const {
    if (n != nullptr){
    	os << n->el << " ";
    	imprimirPreorden(os, n->hijoIzq);
    	imprimirPreorden(os, n->hermanoDer);
	}
}

std::vector<std::string> TRIE::autocompletado (std::string str){
	int strLength = 1;
	
	nodo* n = buscarNodo(this->raiz, str[0]);
	
	while(n != nullptr && strLength < str.length()){
		n = buscarNodo(n, str[strLength]);
		strLength++;
	}

	if(this->nodoHoja(n)){
		return std::vector<std::string>();
	}
	else{
		std::vector<std::string> sufijos = recuperarSufijos(n, str);
		
		return sufijos;
	}
}

std::vector<std::string> TRIE::recuperarSufijos(nodo* n, const std::string& prefijo){
	std::vector<std::string> sufijos;
	
	if(n != nullptr){
		if(this->nodoHoja(n)){
			sufijos.push_back(prefijo);
		}
		
		nodo* nHijo = this->hijoIzq(n);
		
		while(nHijo != nullptr){
			std::string nuevoPrefijo = prefijo + nHijo->el;
			std::vector<std::string> sufijosHijos = recuperarSufijos(nHijo, nuevoPrefijo);
			sufijos.insert(sufijos.end(), sufijosHijos.begin(), sufijosHijos.end());
			nHijo = this->hermDer(nHijo);
		}
	}
	
	return sufijos;
}
#endif
