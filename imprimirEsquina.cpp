#include <stdio.h>

//Mostrar las esquinas de la matriz
int main(){

printf("Ingrese los datos de la matriz\n");

int matriz[3][3];//variable de la matriz

//ingresamos los datos de la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &matriz[i][j]);
        
    }
}
printf("\n");

//mostramos los datos de la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("  %d  ", matriz[i][j]);
    }
    printf("\n");
}

printf("Elementos de las esquinas\n");
//Bucle para mostrar las esquinas de la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)//Condicionamos bajo que condiciones se muestra o no los datos y separamos las esquinas 
    {
        if (i == 0 && j == 0)
        {
            printf("   %d   ", matriz[i][j]);
        }
        if (i == 0 && j == 2)
        {
            printf("   %d   ", matriz[i][j]);
        }
        if (i == 2 && j == 0)
        {
            printf("   %d   ", matriz[i][j]);
        }
        if (i == 2 && j == 2)
        {
            printf("   %d   ", matriz[i][j]);
        }
        
    }
    printf("\n");
}

    return 0;
}