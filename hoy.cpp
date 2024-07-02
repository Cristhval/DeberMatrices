#include <stdio.h>

//Filas y columnas de una matriz 

int main (){

int dimensiones;//Variable para las dimensiones de la matriz


printf("Ingrese las dimensiones de la matriz el valor es tanto de filas como columnas\n");
scanf("%d", &dimensiones);//Ingresamos el valor de la dimension

printf("Ingrese los datos de la matriz\n");
int matriz[dimensiones][dimensiones];//Variable de la matriz con sus dimensiones
//ingresamos los numeros a la matriz
for (int i = 0; i < dimensiones; i++)
{
    for (int j = 0; j < dimensiones; j++)
    {
        scanf("%d", &matriz[i][j]);
        
    }
}
printf("\n");
//mostramos la matriz
for (int i = 0; i < dimensiones; i++)
{
    for (int j = 0; j < dimensiones; j++)
    {
        printf("  %d  ", matriz[i][j]);
    }
    printf("\n");
}


int filas = 0; //Variable para contar las filas
int columnas = 0; //Variable para contrar las columnas

filas = sizeof(matriz) / sizeof(matriz[0]); //Realizamos la cuenta digito por digito de la matriz en las filas

columnas = sizeof(matriz[0]) / sizeof(matriz[0][0]);//Realizamos la cuenta de las columnas usando los datos de las filas

printf("La matriz tiene %d  filas\n", filas);//mostramos los resultados
printf("La matriz tiene %d  columnas\n", columnas);//mostramos los resultados 


    return 0;
}