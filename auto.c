#include "auto.h"
// Funzione che in input accetta una matrice di 8 x 8,
// e in output stampa la griglia di gioco  
void viewMatrix(char matrix[COLUMNS_AND_LINES][COLUMNS_AND_LINES]){
    int i,j;
    printf("\n");
    
    // per i che è uguale a 0 che va a 2 che moltiplica il numero di righe
    //ogni riga ha spazio vuoto e | e poi spazio vuoto, quindi avremo tre posizioni 0-1-2
    for(i = 0; i <= 2 * COLUMNS_AND_LINES; i++){ 
        
        //
        if(i % 2 != 0) 
            printf(" ");

        //per j che va da 0 a 2 che moltiplica nr. colonne(16), incrementa
        for(j = 0; j <= 2 * COLUMNS_AND_LINES; j++){
            
            
            if(i%2==0)
            {
                //se j = 0 printa spazio, se j/2 da resto 0 printa spazio
                //altrimenti mi trovo in posizione dispari e printa "==="
                if(j==0)
                    printf(" ");
                if(j%2==0)
                    printf(" ");
                else
                    printf("===");
            }
            else{
                if(j % 2== 0)
                    printf("|");
                else
                    printf(" %c ", matrix[i/2][j/2]);
            }
        }
        printf("\n");
    }
    printf(" ");
    printf("\n");
}

// Funzione che in input prende il numero casuale e diverse percentuali,
// e in output ritorna l'indice di direzione 
int enumerationIndex( int casual_number, int f, int s, int t){
    
    int first = f;
    int second = f +s;
    int third = f +s +t;
    // Verifico in quale range è casual_number
    if (casual_number <= first) {
        printf("\n\nnumero casuale = %d, destra\n\n\n", casual_number);
        return 1;
    }else if(casual_number > first && casual_number <= second ){
        printf("\n\nnumero casuale = %d, sinistra\n\n\n", casual_number);
        return 2;
    }else if(casual_number > second && casual_number <= third ){
        printf("\n\nnumero casuale = %d, avanti\n\n\n", casual_number);
        return 3;
    }else{
        printf("\n\nnumero casuale = %d, indietro\n\n\n", casual_number);
        return 4;
    }
}

// Funzione che in input prende l'array di cars,
// e in output verifica se ci sono state le collisioni 
bool collision(car_struct *cars){
    int i,j;
    bool collision = false;
    
    // Confronto ogni auto con tutte le altre 
    // e verifico se le posizioni x e y coincidono 
    for (i = 0; i < NUMBER_OF_MACHINES; i++) {
        for (j = 0 ; j < NUMBER_OF_MACHINES; j++) {
            if (i != j && cars[i].x == cars[j].x && cars[i].y == cars[j].y) {//macchina[i] != macchina[j]
                //printf("confronto nella prima if\n");
                //printf("confronto macchina[%d], con macchina[%d]\n", i,j);
                printf("la macchina con simbolo %c e l'altra con simbolo %c si sono scontrate nella posizione[%d][%d] ",cars[i].symbol,cars[j].symbol, i,j);
                collision = true;

                return collision;
            }
        }
    }
    return collision;
}

// Funzione che genera e ritorna un numero casuale 
int nCasual(){
    srand((unsigned int)time(NULL));
    
    return rand()%100+1;
}


