#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//Juego basado en flappy bird

// Constantes para definir el tamaño del juego y los obstaculos
const int ancho = 40;
const int alto = 20;
const int alturaSalto = 1;
const int maxObstaculos = 3;

// Variables globales para la posicion del pajaro, puntaje y obstaculos
int posX, posY, puntaje, puntajeMasAlto = 0;
int obstaculoX[maxObstaculos], tuboSuperiorY[maxObstaculos], tuboInferiorY[maxObstaculos];
bool juegoTerminado;

// Funcion para configurar el juego
void Configurar() {
    juegoTerminado = false;
    posX = ancho / 4;
    posY = alto / 2;
    puntaje = 0;

    // Inicializar la posicion de los obstaculos
    for (int i = 0; i < maxObstaculos; i++) {
        obstaculoX[i] = ancho + i * (ancho / maxObstaculos);
        tuboSuperiorY[i] = rand() % (alto - 6) + 1;
        tuboInferiorY[i] = tuboSuperiorY[i] + 3;
    }

    // Ocultar el cursor de la consola
    HANDLE manejadorConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO infoCursor;
    infoCursor.dwSize = 1;
    infoCursor.bVisible = FALSE;
    SetConsoleCursorInfo(manejadorConsola, &infoCursor);
}

// Funcion para dibujar el juego en la consola
void Dibujar() {
    char buffer[alto + 2][ancho + 2];

    // Crear los bordes del juego
    for (int i = 0; i < ancho + 2; ++i) buffer[0][i] = '#';
    for (int i = 1; i <= alto; ++i) {
        buffer[i][0] = '#';
        for (int j = 1; j <= ancho; ++j) {
            bool esObstaculo = false;
            for (int k = 0; k < maxObstaculos; k++) {
                if (j == obstaculoX[k] && (i <= tuboSuperiorY[k] || i >= tuboInferiorY[k])) {
                    esObstaculo = true;
                    break;
                }
            }
            // Dibujar obstaculos y pajaro
            if (esObstaculo) {
                buffer[i][j] = '#';
            } else if (i == posY && j == posX) {
                buffer[i][j] = '>';  // Parte delantera del pajaro
            } else if (i == posY && j == posX - 1) {
                buffer[i][j] = '-';  // Parte media del pajaro
            } else if (i == posY && j == posX - 2) {
                buffer[i][j] = '<';  // Parte trasera del pajaro
            } else {
                buffer[i][j] = ' ';
            }
        }
        buffer[i][ancho + 1] = '#';
    }
    for (int i = 0; i < ancho + 2; ++i) buffer[alto + 1][i] = '#';

    // Posicionar el cursor al inicio de la consola
    HANDLE manejadorConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicionCursor;
    posicionCursor.X = 0;
    posicionCursor.Y = 0;
    SetConsoleCursorPosition(manejadorConsola, posicionCursor);

    // Imprimir el buffer en la consola
    for (int i = 0; i < alto + 2; ++i) {
        for (int j = 0; j < ancho + 2; ++j) {
            if (buffer[i][j] == '#') {
                printf("\033[32m#\033[0m");  // Texto verde para los obstaculos
            } else if (buffer[i][j] == '>' || buffer[i][j] == '-' || buffer[i][j] == '<') {
                printf("\033[43m%c\033[0m", buffer[i][j]);  // Texto amarillo para el pajaro
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Imprimir puntaje y puntaje mas alto
    printf("Puntaje: %d\n", puntaje);
    printf("Puntaje mas alto: %d\n", puntajeMasAlto);
}

// Funcion para manejar la entrada del usuario
void Entrada() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w':  // Saltar
                if (posY > 1)
                    posY -= alturaSalto;
                break;
            case 's':  // Mover hacia abajo
                if (posY < alto)
                    posY += 1;
                break;
        }
    }
}

// Funcion para actualizar la logica del juego
void Logica() {
    for (int i = 0; i < maxObstaculos; i++) {
        if (obstaculoX[i] <= 0) {
            obstaculoX[i] = ancho - 1;
            tuboSuperiorY[i] = rand() % (alto - 6) + 1;
            tuboInferiorY[i] = tuboSuperiorY[i] + 3;
            puntaje++;
        } else {
            obstaculoX[i]--;
        }

        // Verificar colisiones
        if ((posX == obstaculoX[i] || posX - 1 == obstaculoX[i] || posX - 2 == obstaculoX[i]) && (posY <= tuboSuperiorY[i] || posY >= tuboInferiorY[i])) {
            juegoTerminado = true;
        }
    }

    // Verificar si el pollo toca el borde superior o inferior
    if (posY < 1 || posY > alto) {
        juegoTerminado = true;
    }
}

// Funcion para mostrar el menu principal
void MostrarMenu() {
    system("cls");
    printf("==== MENU ====\n");
    printf("1. Iniciar Juego\n");
    printf("2. Controles\n");
    printf("3. Salir\n");
    printf("==============\n");
    printf("Selecciona una opcion: ");
}

// Funcion para mostrar los controles del juego
void MostrarControles() {
    system("cls");
    printf("==== CONTROLES ====\n");
    printf("w - Saltar\n");
    printf("s - Mover hacia abajo\n");
    printf("r - Reiniciar\n");
    printf("t - Volver al menu\n");
    printf("===================\n");
    printf("Presiona cualquier tecla para volver al menu...\n");
    _getch();
}

int main() {
    srand(time(NULL));
    char opcion;

    while (true) {
        MostrarMenu();
        opcion = _getch();

        if (opcion == '1') {
            Configurar();
            while (true) {
                while (!juegoTerminado) {
                    Dibujar();
                    Entrada();
                    Logica();
                    Sleep(30);
                }

                // Mostrar cursor de la consola
                HANDLE manejadorConsola = GetStdHandle(STD_OUTPUT_HANDLE);
                CONSOLE_CURSOR_INFO infoCursor;
                infoCursor.dwSize = 1;
                infoCursor.bVisible = TRUE;
                SetConsoleCursorInfo(manejadorConsola, &infoCursor);

                if (puntaje > puntajeMasAlto) {
                    puntajeMasAlto = puntaje;
                }

                printf("Presiona 'r' para reiniciar el juego o 't' para volver al menu.\n");

                char tecla;
                do {
                    tecla = _getch();
                    if (tecla == 'r') {
                        Configurar();
                    } else if (tecla == 't') {
                        juegoTerminado = false;
                        break;
                    }
                } while (tecla != 'r' && tecla != 't');

                if (tecla == 't') {
                    break;
                }
            }
        } else if (opcion == '2') {
            MostrarControles();
        } else if (opcion == '3') {
            break;
        }
    }

    return 0;
}
