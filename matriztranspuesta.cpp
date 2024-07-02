#include <stdio.h>

//Matriz transpuesta
int main(){

printf("Ingrese los datos de la matriz\n");

int matriz[3][3];//Variable de la matriz
//Ingresamos los datos a la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &matriz[i][j]);
        
    }
}
printf("\n");
//Mostramos los datos de la matriz
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("  %d  ", matriz[i][j]);
    }
    printf("\n");
}

printf("La matriz transpuesta es:\n");
//Mosotramos la matriz trasnpuesta
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("  %d  ", matriz[j][i]);
    }
    printf("\n");
}

return 0;
}