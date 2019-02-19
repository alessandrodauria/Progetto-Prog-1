#ifndef auto_h
#define auto_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defiisco la massima lunghezza del nome della macchina 
#define MAX_NAME_CARS 16
// Definisco il numero di righe e colonne della matrice
#define COLUMNS_AND_LINES 8
// Definisco il massimo numero di auto che contiene la car_struct
#define NUMBER_OF_MACHINES 4

//// Definisco il nuovo tipo enumerativo direction che puo' assumere i valori sotto indicati.
typedef enum { destra = 1, sinistra, avanti, indietro } direction;

// Definisco il nuovo tipo enumerativo bool che puo' assumere i valori False =0 e True =1.
typedef enum { false, true} bool;

// Definisco una struct "car" generica, contenente il nome dalla macchina,
// le coordinate x e y, simbolo identificativo, e percentuale di andare a 
// destra, sinistra avanti e indietro 
typedef struct car {
    
    char name[MAX_NAME_CARS];
    int x;
    int y;
    char symbol;
    int right;
    int left;
    int forwars;
    int back;
    
}car_struct;


/*--------------------------------- prototipi di funzione --------------------------------*/
// Procedura che stampa la griglia di gioco 
void viewMatrix(char [COLUMNS_AND_LINES][COLUMNS_AND_LINES]);
// Funzione che verifica la collissione
bool collision(car_struct *);
// Funzione che ritorna l'indice di direzione
int enumerationIndex(int, int, int, int);
// Funzione che genera e ritorna un numero pseudocasuale
int nCasual(void);

#endif
