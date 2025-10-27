/*
 * PROYECTO: Tic-Tac-Toe
 * MATERIA: Programación Dinámica
 * DOCENTE: Dr. Herman Geovany Ayala Zúñiga
 * ALUMNO: Wolfang Arturo García Méndez
 */

#include <iostream> // Para entrada (cin) y salida (cout)
#include <limits>   // Para limpiar el buffer de entrada en caso de error
#include <cstdlib>  // Para rand() y srand() (números aleatorios)
#include <ctime>    // Para time() (semilla para aleatorios)
#include <thread>   // Para std::this_thread::sleep_for (pausa)
#include <chrono>   // Para std::chrono::milliseconds (pausa)

 // Constantes para el tablero y jugadores
const int TAMANO_TABLERO = 3;
const char JUGADOR_X = 'X';
const char JUGADOR_O = 'O';

// --- PROTOTIPOS DE FUNCIONES ---
void inicializarTablero(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
void mostrarTablero(const char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
void mostrarMenu();
void jugarPartidaPvP(); // Player vs Player
void jugarPartidaCPU(); // Player vs CPU
void realizarJugadaCPU(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
bool realizarJugada(char tablero[TAMANO_TABLERO][TAMANO_TABLERO], char jugador);
char verificarGanador(const char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
void cambiarJugador(char& jugadorActual);

// --- FUNCIÓN PRINCIPAL (MENÚ) ---

/**
 * @brief Función principal que contiene el bucle del menú.
 */
int main() {

    // Inicializa la semilla para números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    char opcionMenu;

    do {
        mostrarMenu();
        std::cin >> opcionMenu;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcionMenu) {
        case '1':
            jugarPartidaPvP(); // Humano vs Humano
            break;
        case '2':
            jugarPartidaCPU(); // Humano vs CPU
            break;
        case '3':
            std::cout << "\nGracias por jugar. ¡Hasta pronto!\n" << std::endl;
            break;
        default:
            std::cout << "\nOpcion NO valida. Intenta de nuevo." << std::endl;
            std::cout << "Presiona Enter para continuar..." << std::endl;
            std::cin.get();
            break;
        }

    } while (opcionMenu != '3');


    return 0;
}


// --- IMPLEMENTACIÓN DE FUNCIONES ---

/**
 * @brief Muestra el menú principal del juego en la consola.
 */
void mostrarMenu() {
    std::cout << "\n\n\n\n\n\n\n\n\n\n";
    std::cout << "===============================\n";
    std::cout << "  BIENVENIDO A TIC-TAC-TOE\n";
    std::cout << "===============================\n";
    std::cout << "1. Jugar (Humano vs Humano)\n";
    std::cout << "2. Jugar (Humano vs CPU)\n";
    std::cout << "3. Salir\n";
    std::cout << "===============================\n";
    std::cout << "Elige una opcion: ";
}

/**
 * @brief Ejecuta una partida completa de Tic-Tac-Toe (Humano vs Humano).
 */
void jugarPartidaPvP() {
    char tablero[TAMANO_TABLERO][TAMANO_TABLERO];
    char jugadorActual = JUGADOR_X;
    char ganador = ' ';
    int movimientos = 0;
    bool juegoTerminado = false;

    inicializarTablero(tablero);

    while (!juegoTerminado) {
        mostrarTablero(tablero);

        while (!realizarJugada(tablero, jugadorActual)) {
            // reintenta
        }

        movimientos++;

        ganador = verificarGanador(tablero);
        if (ganador != ' ') {
            juegoTerminado = true;
            mostrarTablero(tablero);
            std::cout << "¡FELICIDADES! El Jugador " << ganador << " ha ganado." << std::endl;
        }
        else if (movimientos == 9) {
            juegoTerminado = true;
            mostrarTablero(tablero);
            std::cout << "¡JUEGO TERMINADO! Es un empate." << std::endl;
        }
        else {
            cambiarJugador(jugadorActual);
        }
    }

    std::cout << "\nPresiona Enter para volver al menu principal..." << std::endl;
    std::cin.get();
}

/**
 * @brief Ejecuta una partida completa de Tic-Tac-Toe contra el CPU.
 */
void jugarPartidaCPU() {
    char tablero[TAMANO_TABLERO][TAMANO_TABLERO];
    char jugadorActual = JUGADOR_X; // El humano (X) siempre empieza
    char ganador = ' ';
    int movimientos = 0;
    bool juegoTerminado = false;

    inicializarTablero(tablero);

    while (!juegoTerminado) {

        mostrarTablero(tablero);

        if (jugadorActual == JUGADOR_X) {
            // Turno del Humano
            while (!realizarJugada(tablero, JUGADOR_X)) {
                // reintenta
            }
        }
        else {
            // Turno del CPU
            std::cout << "Turno del CPU (O)..." << std::endl;
            realizarJugadaCPU(tablero);
        }

        movimientos++;

        ganador = verificarGanador(tablero);
        if (ganador != ' ') {
            juegoTerminado = true;
            mostrarTablero(tablero);
            if (ganador == JUGADOR_X) {
                std::cout << "¡FELICIDADES! Has ganado." << std::endl;
            }
            else {
                std::cout << "¡Has perdido! El CPU (O) ha ganado." << std::endl;
            }
        }
        else if (movimientos == 9) {
            juegoTerminado = true;
            mostrarTablero(tablero);
            std::cout << "¡JUEGO TERMINADO! Es un empate." << std::endl;
        }
        else {
            cambiarJugador(jugadorActual);
        }
    }

    std::cout << "\nPresiona Enter para volver al menu principal..." << std::endl;
    std::cin.get();
}


/**
 * @brief Lógica de la IA (CPU) para realizar un movimiento.
 * Estrategia: 1. Ganar, 2. Bloquear, 3. Aleatorio.
 * @param tablero El tablero de juego (se modifica).
 */
void realizarJugadaCPU(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]) {

    // Simula que el CPU "piensa"
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // ESTRATEGIA 1: Buscar un movimiento ganador
    for (int i = 0; i < TAMANO_TABLERO; ++i) {
        for (int j = 0; j < TAMANO_TABLERO; ++j) {
            if (tablero[i][j] != JUGADOR_X && tablero[i][j] != JUGADOR_O) {
                char original = tablero[i][j];
                tablero[i][j] = JUGADOR_O; // Prueba el movimiento
                if (verificarGanador(tablero) == JUGADOR_O) {
                    return; // Encontró movimiento ganador
                }
                tablero[i][j] = original; // Revierte
            }
        }
    }

    // ESTRATEGIA 2: Buscar un movimiento para bloquear al jugador
    for (int i = 0; i < TAMANO_TABLERO; ++i) {
        for (int j = 0; j < TAMANO_TABLERO; ++j) {
            if (tablero[i][j] != JUGADOR_X && tablero[i][j] != JUGADOR_O) {
                char original = tablero[i][j];
                tablero[i][j] = JUGADOR_X; // Prueba si el JUGADOR ganaría aquí
                if (verificarGanador(tablero) == JUGADOR_X) {
                    tablero[i][j] = JUGADOR_O; // Bloquea
                    return;
                }
                tablero[i][j] = original; // Revierte
            }
        }
    }

    // ESTRATEGIA 3: Elegir un movimiento aleatorio
    int fila, col;
    do {
        int eleccion = rand() % 9; // Elige casilla aleatoria (0-8)
        fila = eleccion / TAMANO_TABLERO;
        col = eleccion % TAMANO_TABLERO;
    } while (tablero[fila][col] == JUGADOR_X || tablero[fila][col] == JUGADOR_O);

    tablero[fila][col] = JUGADOR_O;
}


/**
 * @brief Inicializa el tablero con números del 1 al 9.
 */
void inicializarTablero(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]) {
    char contador = '1';
    for (int i = 0; i < TAMANO_TABLERO; ++i) {
        for (int j = 0; j < TAMANO_TABLERO; ++j) {
            tablero[i][j] = contador++;
        }
    }
}

/**
 * @brief Muestra el estado actual del tablero en la consola.
 */
void mostrarTablero(const char tablero[TAMANO_TABLERO][TAMANO_TABLERO]) {
    std::cout << "\n\n\n\n\n\n\n\n\n\n";
    std::cout << "  Proyecto Tic-Tac-Toe\n";
    std::cout << "     Jugador 1 (X) - Jugador 2 (O)\n";
    std::cout << std::endl;

    std::cout << "     |     |     \n";
    std::cout << "  " << tablero[0][0] << "  |  " << tablero[0][1] << "  |  " << tablero[0][2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << tablero[1][0] << "  |  " << tablero[1][1] << "  |  " << tablero[1][2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << tablero[2][0] << "  |  " << tablero[2][1] << "  |  " << tablero[2][2] << "  \n";
    std::cout << "     |     |     \n\n";
}

/**
 * @brief Solicita al jugador HUMANO que ingrese su jugada y la valida.
 */
bool realizarJugada(char tablero[TAMANO_TABLERO][TAMANO_TABLERO], char jugador) {
    int eleccion;
    std::cout << "Turno del Jugador " << jugador << ". Elige una casilla (1-9): ";

    if (!(std::cin >> eleccion)) {
        std::cout << "Error: Debes ingresar un numero." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    // Limpiamos el buffer DESPUÉS de una lectura exitosa (cin >> eleccion)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (eleccion < 1 || eleccion > 9) {
        std::cout << "Jugada NO valida: Elige un numero entre 1 y 9." << std::endl;
        return false;
    }

    int fila = (eleccion - 1) / TAMANO_TABLERO;
    int col = (eleccion - 1) % TAMANO_TABLERO;

    if (tablero[fila][col] == JUGADOR_X || tablero[fila][col] == JUGADOR_O) {
        std::cout << "Jugada NO valida: La casilla ya esta ocupada." << std::endl;
        return false;
    }

    tablero[fila][col] = jugador;
    return true;
}

/**
 * @brief Verifica si hay un ganador después de la última jugada.
 */
char verificarGanador(const char tablero[TAMANO_TABLERO][TAMANO_TABLERO]) {
    // 1. Verificar Filas
    for (int i = 0; i < TAMANO_TABLERO; ++i) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return tablero[i][0];
        }
    }

    // 2. Verificar Columnas
    for (int j = 0; j < TAMANO_TABLERO; ++j) {
        if (tablero[0][j] == tablero[1][j] && tablero[1][j] == tablero[2][j]) {
            return tablero[0][j];
        }
    }

    // 3. Verificar Diagonal Principal
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return tablero[0][0];
    }

    // 4. Verificar Diagonal Secundaria
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        return tablero[0][2];
    }

    // Si no hay ganador
    return ' ';
}

/**
 * @brief Cambia el turno del jugador.
 */
void cambiarJugador(char& jugadorActual) {
    if (jugadorActual == JUGADOR_X) {
        jugadorActual = JUGADOR_O;
    }
    else {
        jugadorActual = JUGADOR_X;
    }
}