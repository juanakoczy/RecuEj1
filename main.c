//Escriba un programa que al recibir dos listas simplemente enlazadas ordenadas,
//de como resultado una nueva lista resultante de la resta de la segunda con la primera.

#include <stdio.h>
#include "listas.h"

int main() {
    Lista * lista1 = newLista();
    Lista * lista2 = newLista();

    insertarOrdenado(lista1, newNodo(1));
    insertarOrdenado(lista1, newNodo(2));
    insertarOrdenado(lista1, newNodo(4));
    insertarOrdenado(lista1, newNodo(3));

    insertarOrdenado(lista2, newNodo(1));
    insertarOrdenado(lista2, newNodo(5));
    insertarOrdenado(lista2, newNodo(4));
    insertarOrdenado(lista2, newNodo(8));

    imprimir(lista1);

    imprimir(lista2);


    //Lista * resultado = diferencia(lista1,lista2);

    imprimir(diferencia(lista1,lista2));

    return 0;
}
