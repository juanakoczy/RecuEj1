//
// Created by Usuario on 18/9/2023.
//

#ifndef RECUEJ1_LISTAS_H
#define RECUEJ1_LISTAS_H

#include <stdbool.h>

typedef struct nodo{
    int dato;
    struct nodo * sig;
}Nodo;

typedef struct lista {
    Nodo * cabecera;
}Lista;

Nodo * newNodo (int dato);
Lista * newLista ();

void insertarOrdenado (Lista * lista, Nodo * nodo);
void imprimir (Lista * lista);
Lista * diferencia (Lista * lista1, Lista * lista2);
bool buscar (Lista * lista, int dato);

#endif //RECUEJ1_LISTAS_H
