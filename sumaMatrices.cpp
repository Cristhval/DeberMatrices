#include <stdio.h>

//Suma de matrices
int main(){

printf("Ingrese los datos de la primera matriz\n");

int matriz1[3][3];//Variable de la matriz
int suma[3][3];//vairable de la suma

//Ingresamos datos a la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &matriz1[i][j]);
        
    }
}
printf("\n");
//Imprime la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("  %d  ", matriz1[i][j]);
    }
    printf("\n");
}
printf("\n");
printf("Ingrese los datos de la segunda matriz\n");

int matriz2[3][3];//Segunda matriz
//Ingresamos datos a la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &matriz2[i][j]);
        
    }
}
printf("\n");
//Mostramos la segunda matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("  %d  ", matriz2[i][j]);
    }
    printf("\n");
}

printf("\n");
printf("La suma de las matrices es\n");
//Realizamos la suma de las matrices
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        suma[i][j] = matriz1[i][j] + matriz2[i][j];
        printf("  %X  ", suma[i][j]);//Usamos %X para transformar la suma a hexadecimal
    }
    printf("\n");
}


    return 0;
}
