//  main.c
//                          ****************************
//                          * [SIMULATORE AUTOSCONTRO] *
//                          ****************************

//                           [FINALITA' DEL PROGRAMMA]

// il seguente programma simula l'autoscontro, abbiamo quattro macchine poste al centro
// dei quattro lati opposti di una griglia 8 x 8. Le auto possono muoversi all'interno 
// della griglia una alla volta in una delle quattro posizioni vicine, il movimento delle 
// auto è dato dalla generazione del numero casuale, infatti ognuna delle 4 auto può muoversi
// a destra a sinistra in avanti e indietro con una certa probabilità, quindi in base al 
// numero casuale che esce che va da 1 a 100 l'auto andrà nella direzione corretta. Infine
// la simulazione finisce quando si verifica uno scontro tra almeno due macchine


//-------------------------------------------------------------------------------------------------
//                          [INCLUSIONE DELLE LIBRERIE]

//                          Includo le librerie standard 

// "stdio.h" è libreria standard del C che contiene definizioni di macro,
// costanti e dichiarazioni di funzioni e tipi usati per le varie operazioni di input/output.
#include <stdio.h>
// "stdlib.h" dichiara funzioni e costanti di utilità generale: allocazione della memoria,
// controllo dei processi, e altre funzioni generali comprendenti anche i tipi di dato.
#include <stdlib.h>
//time.h è l'header file della libreria standard del C che fornisce un accesso standardizzato
// alle funzioni di acquisizione e manipolazione del tempo.
#include <time.h>
//                           Includo la mia libreria 
// "auto.h" implementa l'enum, struct e funzioni che servono per il corretto funzionamento 
// del programma.
#include "auto.h"

//-------------------------------------------------------------------------------------------------------------

//                                       [STRUCT]

 // Di seguito è riportato l'elenco di auto che partecipano all'autoscontro,
 //  ogni auto è identificata dalle coordinate x e y, presenta il proprio simbolo identificativo,
 // inolte sono state implementate anche le percentuali in base alle quali l'auto va a destra,
 // sinistra, avanti e indietro.
car_struct cars[] = {
    {"Ferrari Mondial", 3, 0, 'A', 30, 10, 30, 30},
    {"Maserati Biturbo", 0, 3, 'B', 40, 10, 15, 35},
    {"Porsche 914", 3, 7, 'C', 30, 20, 5, 45},
    {"Fiat 130", 7, 3, 'D', 20, 30, 25, 25}
};



int main(int argc, const char * argv[]) {
    //-------------------------------------------------------------------------------------------------------------------------------
    //                                                [DICHIARAZIONE DELLE VARIABILI]

    // Utilizzo le variabili k,j di tipo intero, necessari per iterare il ciclo for  
    int k,j;

    // Utilizzo "casual_number", variabile di tipo intero all'interno della quale viene
    // salvato il numero casuale  
    int casual_number;

    // Utilizzo la variabile "a" di tipo intero,mi serve quando facciamo lo 'scanf'
    // chiediamo all'utente di memorizzare all'interno di "a" la sua scelta,
    // così da proseguire il gioco  
    int a;

    // Utilizzo la variabile "direction_car" di tipo direction, che serve per far capire 
    // all'auto quando deve andare a destra, sinistra, avanti o indietro
    direction direction_cars;

    // Utilizzo "matrix[8][8]" la variabile di tipo char 
    char matrix[8][8];

    //inizializzo la matrice a vuoto  
    for (k = 0; k < 8; k++) {
        for (j = 0; j < 8; j++) {
            matrix[k][j] = ' ';
        }
    }
    
    // inizializzo le posizioni iniziali delle auto, assegnando le coordinate x e y.
    matrix[3][0] = cars[0].symbol;
    matrix[0][3] = cars[1].symbol;
    matrix[3][7] = cars[2].symbol;
    matrix[7][3] = cars[3].symbol;
    
    
    printf("\n");   
    printf(" ");    
    
    // Funzione che stampa la griglia di gioco 
    viewMatrix(matrix);
    
    // Variabile che indica se le auto si sono scontrate 
    bool crashed = false;

    // Se la condzione risulta falsa allora il ciclo while itera finchè 
    // la condizione non risulta vera
    while (!crashed) {

        // Ad ogni turno itero tutte le 4 auto 
        for (k = 0; k < 4; k++) {
            casual_number =  nCasual();
            direction_cars = enumerationIndex(casual_number, cars[k].right, cars[k].left, cars[k].forwars);
            
            // Lo swich gestisce le casistiche che il valore "direction_cars" può assume.
            switch (direction_cars) {

                // Quando assumerà caso "avanti", e l'auto non si trova sul margine superiore   
                case avanti: 

                    if (cars[k].x > 0) {
                        // Cancello vecchia posizione
                        matrix[cars[k].x][cars[k].y] = ' ';
                        // muovo in avanti
                        cars[k].x -= 1;                                       
                        matrix[cars[k].x][cars[k].y] = cars[k].symbol;  
                        printf("La %s con simbolo %c si e' spostata in avanti in [%d][%d]\n", cars[k].name, cars[k].symbol,cars[k].x+1, cars[k].y+1);
                        crashed = collision(cars);

                    // Altrimenti rimani fermo    
                    }else{
                        printf("La %s con simbolo %c e' rimasta ferma\n\n", cars[k].name, cars[k].symbol);
                    }
                    
                    break;

                // Quando assumerà caso "indietro", e l'auto non si trova sul bordo inferiore    
                case indietro:

                    if (cars[k].x < COLUMNS_AND_LINES-1){
                        // Cancello vecchia posizione
                        matrix[cars[k].x][cars[k].y] = ' ';
                        // Muovo in indietro
                        cars[k].x += 1;
                        matrix[cars[k].x][cars[k].y] = cars[k].symbol;
                        printf("La %s con simbolo %c si e' spostata in indietro in [%d][%d]\n", cars[k].name, cars[k].symbol,cars[k].x+1, cars[k].y+1);
                        crashed = collision(cars);

                    // Altrimenti rimani fermo    
                    }else{
                        printf("La %s con simbolo %c e' rimasta ferma\n\n", cars[k].name, cars[k].symbol);
                    }
                    break;
                // Quando assumerà caso "destra", e l'auto non si trova sul bordo destro.    
                case destra:
                    
                    if (cars[k].y < COLUMNS_AND_LINES-1){
                        // Cancello vecchia posizione
                        matrix[cars[k].x][cars[k].y] = ' ';
                        // Muovo a destra 
                        cars[k].y += 1;
                        matrix[cars[k].x][cars[k].y] = cars[k].symbol;
                        printf("La %s con simbolo %c si e' spostata a destra in [%d][%d]\n", cars[k].name, cars[k].symbol,cars[k].x+1, cars[k].y+1);
                        crashed = collision(cars);

                    // Altrimenti resta fermo   
                    }else{
                        printf("La %s con simbolo %c e' rimasta ferma\n\n", cars[k].name, cars[k].symbol);
                    }
                    break;

                // Quando assumerà caso "sinistra", e l'auto non si trova sul bordo sinistro    
                case sinistra:
                    
                    if (cars[k].y > 0) {
                        // Cancello vecchia posizione
                        matrix[cars[k].x][cars[k].y] = ' ';
                        // Muovo a sinistra 
                        cars[k].y -= 1;
                        matrix[cars[k].x][cars[k].y] = cars[k].symbol;
                        printf("La %s con simbolo %c si e' spostata sinistra in [%d][%d]\n", cars[k].name, cars[k].symbol,cars[k].x+1, cars[k].y+1);
                        crashed = collision(cars);

                    //  Altrimenti resta fermo  
                    }else{
                        printf("La %s con simbolo %c e' rimasta ferma\n\n", cars[k].name, cars[k].symbol);
                    }
                    
                    break;
                    
                default:
                    return 0;
                    
            
            }
            printf("premi 4 per verificare se e' avvenuto lo scontro' : ");
            scanf("%d", &a);
        }
        printf("\n\n**********************************************************\n\n\n");
        viewMatrix(matrix);
    }
    
    
    return 0;
}
