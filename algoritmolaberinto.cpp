#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <algorithm> // Para random_shuffle

using namespace std;

// Estructura para almacenar las coordenadas y el número de pasos
struct Nodo {
    int x, y, pasos;
    vector<pair<int, int>> camino; // Para almacenar el camino recorrido
};

// Función para imprimir el laberinto con colores
void imprimirLaberinto(const vector<vector<int>>& laberinto) {
    for (const auto& fila : laberinto) {
        for (const auto& celda : fila) {
            if (celda == 1)
                printf("\033[41m \033[0m"); // Paredes en rojo
            else
                printf("\033[47m \033[0m"); // Pasillos en blanco
        }
        printf("\n");
    }
}

// Función para imprimir el laberinto con el camino trazado
void imprimirLaberintoConCamino(const vector<vector<int>>& laberinto, const vector<pair<int, int>>& camino) {
    vector<vector<int>> laberintoConCamino = laberinto;
    for (const auto& paso : camino) {
        laberintoConCamino[paso.first][paso.second] = 2; // Marcar el camino
    }

    for (const auto& fila : laberintoConCamino) {
        for (const auto& celda : fila) {
            if (celda == 1)
                printf("\033[41m \033[0m"); // Paredes en rojo
            else if (celda == 2)
                printf("\033[42m \033[0m"); // Camino en verde
            else
                printf("\033[47m \033[0m"); // Pasillos en blanco
        }
        printf("\n");
    }
}

// Función auxiliar para realizar DFS y asegurar un camino válido
void dfs(vector<vector<int>>& laberinto, int x, int y) {
    // Movimientos posibles: arriba, abajo, izquierda, derecha
    vector<pair<int, int>> movimientos = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    random_shuffle(movimientos.begin(), movimientos.end());

    for (const auto& mov : movimientos) {
        int nx = x + mov.first * 2;
        int ny = y + mov.second * 2;

        if (nx > 0 && static_cast<unsigned int>(nx) < laberinto.size() - 1 && 
            ny > 0 && static_cast<unsigned int>(ny) < laberinto[0].size() - 1 && 
            laberinto[nx][ny] == 1) {
            laberinto[nx - mov.first][ny - mov.second] = 0;
            laberinto[nx][ny] = 0;
            dfs(laberinto, nx, ny);
        }
    }
}

// Función para generar un laberinto aleatorio
vector<vector<int>> generarLaberinto(int filas, int columnas) {
    vector<vector<int>> laberinto(filas, vector<int>(columnas, 1));

    // Inicialización del generador de números aleatorios
    srand(time(0));

    // Crear caminos en el laberinto usando DFS
    laberinto[1][1] = 0;
    dfs(laberinto, 1, 1);

    // Asegurar la entrada y la salida del laberinto
    laberinto[1][0] = 0; // Entrada
    laberinto[1][1] = 0; // Asegurar un camino inicial desde la entrada

    // Conectar el pasillo con la salida
    laberinto[filas - 2][columnas - 1] = 0; // Salida
    laberinto[filas - 2][columnas - 2] = 0; // Paso anterior a la salida

    // Asegurar un camino desde el pasillo hacia la salida
    if (laberinto[filas - 3][columnas - 2] == 1) {
        laberinto[filas - 3][columnas - 2] = 0;
        laberinto[filas - 3][columnas - 1] = 0;
    }

    return laberinto;
}

// Función para encontrar el camino más corto desde la entrada hasta la salida usando BFS
vector<pair<int, int>> encontrarCamino(const vector<vector<int>>& laberinto) {
    int filas = laberinto.size();
    int columnas = laberinto[0].size();
    vector<vector<bool>> visitado(filas, vector<bool>(columnas, false));
    queue<Nodo> q;

    // Inicio en la entrada del laberinto
    q.push({1, 0, 0, {{1, 0}}});
    visitado[1][0] = true;

    // Movimientos posibles: arriba, abajo, izquierda, derecha
    vector<pair<int, int>> movimientos = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        Nodo actual = q.front();
        q.pop();

        // Verificar si hemos llegado a la salida
        if (actual.x == filas - 2 && actual.y == columnas - 1) {
            printf("Pasos necesarios para llegar a la salida: %d\n", actual.pasos);
            return actual.camino;
        }

        for (const auto& mov : movimientos) {
            int nx = actual.x + mov.first;
            int ny = actual.y + mov.second;

            if (nx >= 0 && nx < filas && ny >= 0 && ny < columnas && 
                laberinto[nx][ny] == 0 && !visitado[nx][ny]) {
                visitado[nx][ny] = true;
                vector<pair<int, int>> nuevoCamino = actual.camino;
                nuevoCamino.push_back({nx, ny});
                q.push({nx, ny, actual.pasos + 1, nuevoCamino});
            }
        }
    }

    // Retornar un camino vacío si no se encuentra un camino válido
    return {};
}

int main() {
    int filas, columnas;

    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    // Validar las entradas del usuario
    if (filas < 3 || columnas < 3) {
        printf("El numero de filas y columnas debe ser al menos 3 para crear un laberinto valido.\n");
        return 1;
    }

    vector<vector<int>> laberinto = generarLaberinto(filas, columnas);
    
    printf("Laberinto generado:\n");
    imprimirLaberinto(laberinto);

    vector<pair<int, int>> camino = encontrarCamino(laberinto);
    
    if (!camino.empty()) {
        printf("Camino hacia la salida:\n");
        imprimirLaberintoConCamino(laberinto, camino);
    } else {
        printf("No se encontro un camino hacia la salida.\n");
    }

    return 0;
}
