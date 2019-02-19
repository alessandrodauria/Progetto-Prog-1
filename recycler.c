#include "recycler.h"


/*----------------------funzioni--------------------*/

// La "printProductList" ? una procedura che dato in imput un array di prodotti,
// in output stampa la lista di quest'ultimi.
void printProductList(product_struct *products_list){

    // Indice dei prodotti che nel ciclo for viene inizializzato a 0.
	int index_of_product;
    // Numero massimo di prodotti che contiene il mio array 
	int size_product = 26;
    // Il ciclo for scorre su tutti gli elementi dell'aray di "products_list" 
    // e la "printf" stampa tuti gli elemti contenuti nellarray.
	for(index_of_product = 0; index_of_product < size_product; index_of_product++)
        {
          printf("%d. %s\n", index_of_product+1, products_list[index_of_product].name);
        }
}

// Funzione "isProductAvailable" di tipo booleano che pu? assumere valore {true=1, false=0},
// dato in imput un prodotto e la lista di prodotti
// in output la funzione "isProductAvailable" ritorna vero se i prodotti sono disponibili  
// falso se i prodotti non sono disponibili.
bool isProductAvailable(int product, product_struct *products_list){
	return products_list[product-1].number_of_pruducts < MAX_NUMBER_OF_PRODUCT;
	
}

// Funzione "isBudgetAvailable" di tipo booleano che pu? assumere valore {true=1, false=0},
// dato in imput un prodotto, la lista di prodotti e recycler_struct
// in output ritorna vero se il budget ? disponibile 
// falso se non ? cos?.
bool isBudgetAvailable(int product, product_struct *products_list, recycler_struct *recycler){
	return products_list[product-1].revenue <= recycler->initial_budget;
}

// La "increaseRecycledProduct" ? una procedura che dato in imput un prodotto e la lista di prodotti, 
// in output incrementa il numero dei prodotti smaltiti.
void increaseRecycledProduct(int product, product_struct *products_list){
	products_list[product-1].number_of_pruducts += 1;
}

// La "decreseBudget" ? una procedura che dato in imput un prodotto, la lista di prodotti e recycler_struct, 
// in output decrementa il budget iniziale.
void decreseBudget(int product, product_struct *products_list, recycler_struct *recycler){
	 recycler->initial_budget -= products_list[product-1].revenue;
}

// La "printRecycledProduct" ? una procedura che dato in imput un array di prodotti,
// in output stampa la lista di quest'ultimi.
void printRecycledProduct(product_struct *products_list){
    int size_product = 26;
    int index_of_day;
	// Il ciclo for scorre su tutti gli elementi dell'aray di "products_list" 
    // e la "printf" stampa tuti gli elemti che sono stati smaltiti.
	for(index_of_day = 0; index_of_day < size_product; index_of_day++){
          if (products_list[index_of_day].number_of_pruducts > 0) {
            printf("%d %s\n",products_list[index_of_day].number_of_pruducts,products_list[index_of_day].name);
          }
          
        }
}




