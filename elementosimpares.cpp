#include <stdio.h>

//Elementos impares de la matriz
int main(){

printf("Ingrese los datos de la matriz\n");

int matriz[3][3];//Variable de la matriz

//Ingresamos los datos de la matris por medio de un bucle
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

printf("Los elementos impares son\n");

//Mostramos los elementos impares 
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        if (matriz[i][j] % 2 !=0)//Condicionamos para conseguir numeros pares
        {
            printf("  %d  ", matriz[i][j]);
        }
        
    }
    printf("\n");
}

    return 0;
}