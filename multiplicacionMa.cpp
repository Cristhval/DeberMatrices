#include <stdio.h>

//Multiplicacion de matrices
int main() {

printf("Ingrese los datos de la primera matriz\n");

int matriz1[3][3];//Variable de la matriz1
int matriz2[3][3];//Variable de la matriz2
int resultado[3][3];//Variable para el resultado

//Ingresamos los datos a la primera matriz
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }
    printf("\n");

//Mostramos los datos de la primera matriz
printf("Primera matriz:\n");

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            printf("  %d  ", matriz1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Ingrese los datos de la segunda matriz\n");

//Ingresamos los datos de la segunda matriz
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }
    printf("\n");

//Mostramos los datos de la segunda matriz
    printf("Segunda matriz\n");

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            printf("  %d  ", matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

//Iniciamos la matriz resultado
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
        }
    }

//Multiplicacion de las matrices
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

//Mostramos el resultado
    printf("La multiplicacion de las matrices es\n");

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            printf("  %d  ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
