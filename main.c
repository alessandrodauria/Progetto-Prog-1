

//                           [FINALITA' DEL PROGRAMMA]

// Il seguente programma simula la gestione di un riciclatore automatico di rifiuti. 
// Permette all'utente di riciclare 5 tipi di categorie di rifiuti differenti come plastica,
// alluminio, carta, vetro e umido. Ogni tipo di categoria presenta una lista di prodotti 
// possibili da smaltire. Inoltre ogni prodotto è identificato da un nome, codice identificativo 
// e dal prezzo di riciclo. il nostro riciclatore presenta un budget iniziale il quale viene decrementato
// ogni qualvolta che si ricicla un prodotto, se il budget è presente allora si procede allo smaltimento,
// inoltre ogni singolo rifiuto può essere smaltito Massimo 20 volte. Un'altra delle funzioni più importanti  
// è la possibilità di visualizzare l'elenco dei prodotti riciclati.  
//------------------------------------------------------------------------------------------------------------

//                          [INCLUSIONE DELLE LIBRERIE]

//                          Includo le librerie standard 

// "STDIO.h" è libreria standard del C che contiene definizioni di macro,
// costanti e dichiarazioni di funzioni e tipi usati per le varie operazioni di input/output.
#include <stdio.h>
// "STDLIB.h" dichiara funzioni e costanti di utilità generale: allocazione della memoria,
// controllo dei processi, e altre funzioni generali comprendenti anche i tipi di dato.
#include <stdlib.h>
//                           Includo la mia libreria 
// "RECYCLER.h" implementa l'enum, struct e funzioni che servono per il corretto funzionamento 
// del programma.
#include "recycler.h"
 
//-------------------------------------------------------------------------------------------------------------

//                                       [STRUCT]

 // Di seguito è riportato un elenco di rifiuti che è possibile smaltire,
 // i rifiuti sono divisi in 5 categirie, plastica, allumionio, carta, vetro e umido. 
 // Ogni prodotto è identificato da un nome, codice identificativo e prezzo di riciclo.
 // Inoltre lo smaltimento di ogni prodotto è stato inizializzato a 0, in modo tale che 
 // ogni volta che viene reciclato un prodotto questo viene incrementato a un Massimo di 20 unità. 

product_struct products_list[] = {
   //-------------Plastica-----------------
   {"bottiglie", 2, 0.15, 0},
   {"flaconi", 2, 0.15, 0},
   {"pellicole di giornali e riviste", 2, 0.20, 0},
   {"film e pellicole", 2, 0.18, 0},
   //-------------Allumionio------------------
   {"lattine", 5, 0.14, 0},
   {"tappi e capsule", 5, 0.14, 0},
   {"tubetti", 5, 0.14, 0},
   {"coperchi per yogurt", 5, 0.14, 0},
   {"fogli in alluminio per alimenti", 5, 0.14, 0},
   {"bombolette spray non infiammabili", 5, 0.19, 0},
   {"scatoletta e barattoli per carne,pesci e legumi", 5, 0.14, 0},
   //---------------Carta-----------------
   {"giornali, riviste, libri, quaderni", 3, 0.16, 0},
   {"moduli continui", 3, 0.16, 0},
   {"scatole di prodotti alimentari e imballaggi in cartone", 3, 0.16, 0},
   {"poliaccoppiati, senza parti in plastica e residui", 3, 0.16, 0},
   //---------------Vetro-----------------
   {"bicchiere di vetro", 1, 0.17, 0},
   {"vasetti di vetro", 1, 0.17, 0},
   {"vetri rotti", 1, 0.17, 0},
   {"flaconi (no medicinali)", 1, 0.17, 0},
   {"bottiglie di vetro", 1, 0.17, 0},
   //----------------Umido-------------------
   {"resti di frutta e ortaggi", 4, 0.18, 0},
   {"resti di carne e pesce", 4, 0.18, 0},
   {"alimenti deteriorati", 4, 0.21, 0},
   {"carta e cartone sporchi", 4, 0.25, 0},
   {"fondi di te' e caffe'", 4, 0.29, 0},
   {"gusci d'uovo", 4, 0.24, 0},

};

// Con la seguente struct inizializzo il budget iniziale del reciclatore 
recycler_struct recycler = {
  100.00, products_list
};

int main(){
  //-------------------------------------------------------------------------------------------------------------------------------
  //                                                [DICHIARAZIONE DELLE VARIABILI]
  // Utilizzo la variabile ' menu_chice ' di tipo intero, per rappresentare un numero che va da 0 a n,
  // quando facciamo lo 'scanf' chiediamo all'utente di memorizzare all'interno di menu_choice la sua scelta,
  // che da menù può essere o [1, 2 , 3].  
  int menu_choice;


  // Utilizzo la variabile ' product_list ' di tipo intero, per rappresentare un numero intero che va da 0 a n,
  // quando facciamo lo 'scanf' chiediamo all'utente di memorizzare all'interno di product_choice la sua scelta,
  // che va da [1 a 26].  
  int product_choice;

  // Vriabile di tipo intero che utilizzo nel ' while ' che mette in funzione il "clear buffer".
  int ch;

  // Dichiaro una variabile di tipo puntatore che punta ad un tipo della struct ' recycler_struct ',
  // ed è uguale all'inirizzo di memoria di ' recycler '. Serve per cambiare il valore di una variabile 
  // passando il suo indirizzo di memoria.
  recycler_struct *rec = &recycler;

  //-----------------------------------------------------------------------------------------------------------------------------------
    //                                                    INTRODUZIONE

    printf("\n\n***************************** BENVENUTO, SONO UN RICICLATORE DI RIFIUTI **************************************\n");

    printf("\n----------------------------------------------------------------------------------------------------------------\n");
    printf("|   Perche' riciclare? Riciclare i rifiuti significa valorizzare i rifiuti, recuperando materie prime,         |\n");
    printf("|   anziche' smaltirli direttamente in discarica ed inceneritori. Questa attivita',                            |\n");
    printf("|   e' indispensabile per aiutare il nostro pianeta, in quanto riduce il consumo di materie prime,             |\n");
    printf("|   l' utilizzo di energia e l' emissione di gas serra associati!                                              |\n");
    printf("----------------------------------------------------------------------------------------------------------------\n\n");

    // Utilizzo il costrutto ' while ' per far entrare in ciclo continuo le opzioni proposte all'utente 
    // ovvero il ' Menù '. Nel while posiziono (-1) perchè fino a quando la scelta dall'utente non sarà (-1)
    // il programma si ripeterà all'infinito fino a quando l'utente non preme 3, funzione che termina il programma.
    while(menu_choice != -1){

        printf("Come ti posso aiutare?\n\n");
        
        // MENU' = Opzioni proposte all'utente.
        printf("- Per reciclare il prodotto premi 1\n");
        printf("- Per mostrare il resoconto della giornata premi 2\n");
        printf("- Per uscire premi 3\n\n");
        
        printf("inserisci la tua scelta: ");

        // Viene considerata la selezione dell'utente ed 
        // e' memorizzata nella variabile ' menu_choice '. 
        scanf("%d", &menu_choice);

         //mette in funzione il "clear buffer"
        while((ch = getchar()) != '\n'&& ch != EOF);    
        
        // Lo swich gestisce le casistiche che il valore menu_choice può assume 
        switch (menu_choice)
        {
            // quando assumera valore 1 -> permette all'utente di scegliere il prodotto che desidera smaltire,
            // verifica se non sono stati smaltiti più di 20 prodotti, e se il denaro non è esaurito. 
            case 1:
                
                printf("\n-------------------------------------");
                printf("\n-  scegli il prodotto da smaltire:  -\n");
                printf("-------------------------------------\n\n");
                
                printProductList(products_list);           /*------funzione in libreria*/
                
                printf("\ninserisci la tua scelta: ");
                scanf("%d", &product_choice);
                while((ch = getchar()) != '\n'&& ch != EOF);
                printf("\nHai scelto di smaltire: %s\n", products_list[product_choice-1].name);
                
                // Funzione che verifica se il prodotto non è stato smaltito più di 20 volte
                // se non è stato smaltito più di 20 volte, si pasa alla funzione ' isBudgetAvailable ' 
                // se è stato smaltito già 20 volte allora vai a ' else '
                if (isProductAvailable(product_choice, products_list)) {

                    // Funzione che verifica se il budget a disposizione non è esaurito,
                    // se non è esaurito, si passa alla funzione che incrementa il numero
                    // di prodotti smaltiti 'increaseRecycledProduct' .
                    if (isBudgetAvailable(product_choice, products_list, rec)) {

                        // Funzione che incrementa il numero di prodotti smaltiti 
                        increaseRecycledProduct(product_choice, products_list);

                        // Funzione che decrementa il budget ogni volta che viene smaltito un prodotto 
                        decreseBudget(product_choice, products_list, rec);
                        
                        // L
                        printf("Oggi puoi smaltire ancora %d %s", (MAX_NUMBER_OF_PRODUCT - products_list[product_choice-1].number_of_pruducts), products_list[product_choice-1].name);
                        printf("\n\n**************************\n");
                        printf("* SALDO RIMANENTE %0.2f *\n", recycler.initial_budget);
                        printf("**************************\n\n"); 
    
                    // Caso in cui il saldo a disposizione è esaurito     
                    } else {
                        printf("\nSaldo esaurito");
                        printf("\nContattare asitestenza clienti 334 889 2230\n");
                        return 0;
                    }

                // Caso in cui il prodotto è stato smaltito più di 20 volte    
                } else {
                    printf("\n\n-----------------------------------------------");
                    printf("\nNon posso piu' smaltire questo tipo di prodotto\n");
                }
                break;

            // valore 2 -> Stampa la lista dei prodotti smaltiti fino a quel momento.    
            case 2:
                printf("\nOggi sono stati smaltiti:\n");

                // Funzione che stampa la lista dei prodotti smaltiti fino al momento della richiesta dell'utente.
                printRecycledProduct(products_list);
                printf("\n\n");
                break;

             // valore 3 -> esce dal programma.    
            case 3:
                printf("       _-_\n    /~~   ~~\\ \n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n");
                printf("Grazie, con il tuo contributo hai migliorato l'ambiente");
                
                return 0;
                
            // Caso in cuoi l'utente inserisca una sceltà non prevista dal programma.    
            default:
                printf("\aSCELTA' NON VALIDA\n\n");
                break;
        }
        printf("\n=============================================================\n\n");
    } 

   
    return 0;
}

