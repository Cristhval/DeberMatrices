#include <stdio.h>

//Matriz simetrica

//Funcion para verificar si una matriz es simetrica

bool esSimetrica(int matriz1[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz1[i][j] != matriz1[j][i]) {
                return false;//devolvemos el resultado
            }
        }
    }
    return true;//devolvemos el resultado
}


int main(){

printf("Ingrese los datos de la matriz\n");

int matriz1[3][3];//declaramos la variable para la matriz

//Ingresamos los datos de la matriz por un bucle
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &matriz1[i][j]);
        
    }
}
printf("\n");

//Mostramos la matriz por un bucle
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("  %d  ", matriz1[i][j]);
    }
    printf("\n");
}

printf("\n");

 //Verificar si la matriz es simetrica

    if (esSimetrica(matriz1)) {
        printf("La matriz es simetrica\n");
    } else {
        printf("La matriz no es simetrica\n");
    }

    return 0;
}