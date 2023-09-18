//
// Created by Usuario on 18/9/2023.
//

#include "listas.h"
#include "malloc.h"
#include "stdio.h"

Nodo * newNodo (int dato){

    Nodo * aux = NULL;
    aux = malloc(sizeof(Nodo));

    if (aux == NULL){
        printf("No hay espacio de memoria suficiente.");
        exit(-1);
    }
    else{
        aux->dato = dato;
        aux->sig = NULL;
    }
    return aux;
}
Lista * newLista (){
    Lista * aux = NULL;
    aux = malloc(sizeof(Lista));

    if (aux == NULL){
        printf("No hay espacio de memoria suficiente.");
        exit(-1);
    }
    else{
        aux->cabecera = NULL;
    }
    return aux;
}

void insertarOrdenado (Lista * lista, Nodo * nodo){

    Nodo * aux = lista->cabecera;
    Nodo * anterior = NULL;

    if (aux == NULL){//la lista esta vacia
        lista->cabecera = nodo;
    }
    else {
        while (aux != NULL && aux->dato < nodo->dato) {
            anterior = aux;
            aux = aux->sig;
        }
        if (anterior == NULL) {// Si el nuevo nodo debe ir al principio de la lista
            nodo->sig = lista->cabecera;
            lista->cabecera = nodo;
        } else { // Insertar el nuevo nodo entre el nodo anterior y el actual
            anterior->sig = nodo;
            nodo->sig = aux;
        }
    }
}

void imprimir (Lista * lista){

    Nodo * aux = lista->cabecera;
    for(; aux!=NULL; aux = aux->sig){
        printf("\t%d\t", aux->dato);
    }
    printf("\n");
}

bool buscar (Lista * lista, int dato){

    Nodo * aux = lista->cabecera;
    while (aux->sig!=NULL){
        if (aux->dato ==  dato) {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

Lista * diferencia (Lista * lista1, Lista * lista2){

    Nodo * aux1 = lista1->cabecera;

    Nodo * NodoAInsertar = NULL;
    Lista * resultado = newLista();

    while (aux1->sig!=NULL){
        if (!buscar(lista2,aux1->dato)){
            NodoAInsertar = newNodo(aux1->dato);
            insertarOrdenado(resultado,NodoAInsertar);
        }
        aux1 = aux1->sig;
    }

    return resultado;
}