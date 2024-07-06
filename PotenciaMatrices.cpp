#include <stdio.h>

//Potencia de matrices

//Funcion para multiplicar dos matrices de 3x3
void multiplicarMatrices(int a[3][3], int b[3][3], int resultado[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

//Funcion para copiar una matriz en otra
void copiarMatriz(int origen[3][3], int destino[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            destino[i][j] = origen[j][i];
        }
    }
}

int main() {
    
printf("Ingrese los datos de la primera matriz \n");

int matriz[3][3];//Variable de la matriz original
int resultado[3][3];//Variable para el resultado
int temporal[3][3];//Matriz temporal para operaciones

//Ingresamos los datos a la matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

printf("Ingrese la potencia de la matriz:\n");

int potencia;//Variable de la potencia

scanf("%d", &potencia);

//Inicializamos la matriz resultado como la identidad
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)
                resultado[i][j] = 1;
            else
                resultado[i][j] = 0;
        }
    }

//Calculamos la potencia de la matriz
    for (int p = 0; p < potencia; p++) {
        multiplicarMatrices(resultado, matriz, temporal);
        copiarMatriz(temporal, resultado);
    }

//Mostramos el resultado
printf("La matriz elevada a la potencia %d es:\n", potencia);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("  %d  ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
