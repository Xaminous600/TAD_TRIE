# Autocompletado Eficiente con Árbol TRIE en C++  

Este proyecto presenta una implementación de un **árbol TRIE n-ario** en C++ como una solución eficiente para funcionalidades de autocompletado, búsqueda de palabras por prefijo y otras aplicaciones relacionadas con cadenas de texto.  

## 🚀 Introducción  
El autocompletado tradicionalmente se realiza comparando un texto con los valores de un array predefinido, lo que tiene un costo computacional de **orden lineal (O(n))** respecto al tamaño del array.  
Para optimizar este proceso, se utiliza la estructura de datos **TRIE**, que organiza los caracteres de las palabras en forma de árbol, logrando búsquedas con una eficiencia proporcional a la longitud del prefijo buscado.  

### ¿Qué es un TRIE?  
Un **TRIE** es una estructura de datos especializada para manejar cadenas de texto.  
- Cada nodo del árbol representa un carácter.  
- Las ramas representan posibles continuaciones de las palabras almacenadas.  
- Es ideal para operaciones como:  
  - Autocompletado.  
  - Búsqueda de prefijos.  
  - Correctores ortográficos.  

---

## 🛠️ Detalles de Implementación  

### Estructura del Árbol  
El TRIE se implementa como un **árbol n-ario**, utilizando celdas enlazadas:  
- Cada nodo tiene:  
  - Puntero al padre.  
  - Puntero al hijo izquierdo.  
  - Puntero al hermano derecho.  

### Funcionalidades Principales  
1. **rellenarArbol(string palabra):**  
   Inserta palabras en el árbol, fragmentándolas en caracteres individuales.  

2. **autocompletado(string prefijo):**  
   Recibe un prefijo y devuelve todas las combinaciones posibles que completan dicho prefijo.  

---

## 💡 Mejoras Propuestas  
Si deseas ampliar o personalizar este proyecto, aquí tienes algunas ideas:  
- Utilizar una **tabla hash** para almacenar los hijos de cada nodo, aumentando la eficiencia de búsqueda.  
- Leer palabras desde un archivo de texto para inicializar automáticamente el árbol.  
- Implementar métodos adicionales para:  
  - Eliminar palabras.  
  - Sugerir palabras más frecuentes.  
  - Gestionar datos multilingües.  

## ⚙️ Requisitos  
- **Compilador C++** compatible con C++11 o superior.  
- (Opcional) Archivo `words.txt` para inicializar palabras en el TRIE.
