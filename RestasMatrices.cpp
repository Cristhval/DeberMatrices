#include <stdio.h>

//Resta de matrices
int main(){

printf("Ingrese los datos de la primera matriz\n");

int matriz1[3][3];//Variable de la matriz
int resta[3][3];//Varaible de la resta

//Ingresamos la primera matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &matriz1[i][j]);
        
    }
}
printf("\n");
//Mostramos la primera matriz
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

int matriz2[3][3];//Variable de la segunda matriz

//Ingresamos datos a la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &matriz2[i][j]);
        
    }
}
printf("\n");
//Mostramos la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("  %d  ", matriz2[i][j]);
    }
    printf("\n");
}

printf("\n");
printf("La resta de las matrices es\n");
//Realizamos la resta de matrices
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        resta[i][j] = matriz1[i][j] - matriz2[i][j];
        printf("  %d  ", resta[i][j]);//Mostramos el resultado
    }
    printf("\n");
}


    return 0;
}