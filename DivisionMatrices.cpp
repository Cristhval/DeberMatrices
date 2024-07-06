#include <stdio.h>


//Division de matrices 
int main() {
    printf("Ingrese los datos de la matriz\n");

    float matriz[3][3];//Variable de la matriz
    float aux;//Auxiliar que usaremos mas adelante
    float pivote;//Otro auxiliar 
    float identidad[3][3];//Matriz identidad 
    float determinante = 0;//Variable para el determinante 

//Ingresamos los datos de la matriz
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

//Mostramos los datos de la matriz ingresada
    printf("Matriz ingresada\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("  %f  ", matriz[i][j]);
        }
        printf("\n");
    }

//Calculamos el determinante
    determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[2][1] * matriz[1][2]) -
                   matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[2][0] * matriz[1][2]) +
                   matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[2][0] * matriz[1][1]);

    if (determinante != 0) {//Condicionamos de acuerdo al determinante
//Iniciamos la matriz identidad
        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                identidad[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }

//Proceso de Gauss-Jordan
        for (int i = 0; i < 3; i++) {

            pivote = matriz[i][i];
            for (int k = 0; k < 3; k++) {
                matriz[i][k] /= pivote;
                identidad[i][k] /= pivote;
            }
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    aux = matriz[j][i];
                    for (int k = 0; k < 3; k++) {
                        matriz[j][k] -= aux * matriz[i][k];
                        identidad[j][k] -= aux * identidad[i][k];
                    }
                }
            }
        }

//Mostramos la matriz inversa
        printf("Matriz inversa:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("   %f   ", identidad[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("La matriz no tiene inversa porque su determinante es igual a 0\n");
    }

int matriz2[3][3];//Variable de la matriz2
float resultado[3][3];//Variable para el resultado de la division

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
            printf("   %d   ", matriz2[i][j]);
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
if (determinante !=0)
{
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += identidad[i][k] * matriz2[k][j];
            }
        }
    }
//Mostramos el resultado
printf("La division de las matrices es\n");

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            printf("   %f   ", resultado[i][j]);
        }
        printf("\n");
    }
      
}
else
{
    printf("La matriz no se puede dividir porque es necesario la matriz inversa\n");
}
printf("\n");


    return 0;
}
