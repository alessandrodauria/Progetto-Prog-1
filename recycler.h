//                             [Introduzione alla libreria]
// Insieme di operazioni per agevolare l'utilizzo di un ricilatore 

#ifndef recycler_h
#define recycler_h

// "stdio.h" ? la libreria standard del C che contiene definizioni di macro,
// costanti e dichiarazioni di funzioni e tipi usati per le varie operazioni di input/output.
#include <stdio.h>

// Definisco la massima lunghezza del nome dei prodotti che posso essere smaltiti 
#define MAX_NAME_LENGHT 100
// Definisco il massimo numero di volte che ogni prodotto pu? essere smaltito 
#define MAX_NUMBER_OF_PRODUCT 20

// Definisco il nuovo tipo enumerativo garbage che pu? assumere i valori sotto indicati.
typedef enum{vetro=1,plastica,carta,umido,alluminio} garbage; 
// Definisco il nuovo tipo enumerativo bool che pu? assumere i valori False =0 e True =1.
typedef enum { false, true} bool; 

// Definisco un nuovo tipo struct genrica di prodotti, ogni prodotto ? identificato da un nome, 
// codice identificativo, prezzo di riciclo e il numero di volte che ?
// stato smaltito un certo prodotto.
typedef struct product{
    char name[MAX_NAME_LENGHT];
    int code;
    float revenue;
    int number_of_pruducts;
}product_struct;

// Definisco un nuovo tipo struct che ? necessaria per rappresentare un reciclatore 
typedef struct recycler{
    float initial_budget;
    product_struct *product_array;
}recycler_struct;

/*--------------------------------- prototipi di funzione --------------------------------*/

// Funzione che stampa la lista con tutti i prodotti che ? possibile smaltire
void printProductList(product_struct *); 
// Funzione che verifica se il prodotto non ? stato smaltito pi? di 20 volte
bool isProductAvailable(int,product_struct *);
// Funzione che verifica se il budget a disposizione non ? esaurito
bool isBudgetAvailable(int,product_struct *, recycler_struct *);
// Funzione che incrementa il numero di prodotti smaltiti 
void increaseRecycledProduct(int, product_struct *);
 // Funzione che decrementa il budget ogni volta che viene smaltito un prodotto 
void decreseBudget(int, product_struct *,recycler_struct *);
// Funzione che stampa la lista dei prodotti smaltiti fino al momento della richiesta dell'utente.
void printRecycledProduct(product_struct *);

#endif

