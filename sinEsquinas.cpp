#include <stdio.h>

//Matriz sin esquinas o elementos menos las esquinas
int main(){

printf("Ingrese los datos de la matriz\n");

int matriz[3][3];//Variable de la matriz
//Ingresamos los datos de la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &matriz[i][j]);
        
    }
}
printf("\n");
//Mostramos la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("  %d  ", matriz[i][j]);
    }
    printf("\n");
}

printf("Elementos sin las esquinas\n");
//Matriz sin esquinas por medio de un bucle y condicionales
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)//Condicionamos para que solo muestre los datos que queremos menos las esquinas
    {
        if (i == 0 && j == 1)
        {
           printf("  %d ", matriz[i][j]);//Mostramos los elementos que obtenemos
        }
        if (i == 1 && j == 0)
        {
            printf("%d ", matriz[i][j]);
        }
        if (i == 1 && j == 1)
        {
            printf("%d ", matriz[i][j]);
        }
        if (i == 1 && j == 2)
        {
            printf("%d ", matriz[i][j]);
        }
        if (i == 2 && j == 1)
        {
            printf("  %d ", matriz[i][j]);
        }
        
        
    }
    printf("\n");
}

    return 0;
}