#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // Incluir para la funcion time()

//Orden de cartas

// Definir los palos y valores de las cartas
const char* palos[] = {"C", "D", "T", "P"};
const char* valores[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

typedef struct {
    const char* valor;
    const char* palo;
} Carta;

// Funcion para comparar dos cartas
int comparar_cartas(const void* a, const void* b) {
    Carta* cartaA = (Carta*)a;
    Carta* cartaB = (Carta*)b;
    
    int paloA = 0, paloB = 0, valorA = 0, valorB = 0;
    
    // Asignar valor numerico a los palos
    for (int i = 0; i < 4; i++) {
        if (strcmp(cartaA->palo, palos[i]) == 0) paloA = i;
        if (strcmp(cartaB->palo, palos[i]) == 0) paloB = i;
    }
    
    // Asignar valor numerico a los valores
    for (int i = 0; i < 13; i++) {
        if (strcmp(cartaA->valor, valores[i]) == 0) valorA = i;
        if (strcmp(cartaB->valor, valores[i]) == 0) valorB = i;
    }
    
    // Comparar primero por palo y luego por valor
    if (paloA == paloB) return valorA - valorB;
    else return paloA - paloB;
}

int main() {
    Carta baraja[52];
    int index = 0;
    
    // Crear la baraja
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            baraja[index].palo = palos[i];
            baraja[index].valor = valores[j];
            index++;
        }
    }
    
    // Semilla para el generador de numeros aleatorios
    srand(time(NULL));
    
    // Mezclar la baraja
    for (int i = 0; i < 52; i++) {
        int r = i + rand() / (RAND_MAX / (52 - i) + 1);
        Carta temp = baraja[i];
        baraja[i] = baraja[r];
        baraja[r] = temp;
    }
    
    // Imprimir la baraja desordenada
    printf("Baraja desordenada:\n");
    for (int i = 0; i < 52; i++) {
        printf("%s de %s\n", baraja[i].valor, baraja[i].palo);
    }
    
    // Ordenar la baraja
    qsort(baraja, 52, sizeof(Carta), comparar_cartas);
    
    // Imprimir la baraja ordenada
    printf("\nBaraja ordenada:\n");
    for (int i = 0; i < 52; i++) {
        printf("%s de %s\n", baraja[i].valor, baraja[i].palo);
    }
    
    return 0;
}
