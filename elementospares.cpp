#include <stdio.h>

//Elementos pares de una matriz
int main(){

printf("Ingrese los datos de la matriz\n");

int matriz[3][3];//Variable para la matriz

//Ingresamos los datos a la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &matriz[i][j]);
        
    }
}
printf("\n");

//Mostramos la matriz por medio de un bucle
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("  %d  ", matriz[i][j]);
    }
    printf("\n");
}

printf("Los elementos pares son\n");
//Mostramos los elementos pares por medio de un bucle
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        if (matriz[i][j] % 2 == 0)//Condicionamos los numeros pares para q aparezcan
        {
            printf("  %d  ", matriz[i][j]);
        }
        
    }
    printf("\n");
}
    return 0;
}