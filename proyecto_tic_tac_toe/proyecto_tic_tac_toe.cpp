/*
 * PROYECTO: Tic-Tac-Toe
 * MATERIA: Programación Dinámica
 * DOCENTE: Dr. Herman Geovany Ayala Zúñiga
 * ALUMNO: Wolfang Arturo García Méndez
 */

#include <iostream> // Para entrada (cin) y salida (cout)
#include <limits>   // Para limpiar el buffer de entrada en caso de error

 // Constantes para el tablero y jugadores
const int TAMANO_TABLERO = 3;
const char JUGADOR_X = 'X';
const char JUGADOR_O = 'O';

// --- PROTOTIPOS DE FUNCIONES ---
void inicializarTablero(char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
void mostrarTablero(const char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
void mostrarMenu();
void jugarPartida();
bool realizarJugada(char tablero[TAMANO_TABLERO][TAMANO_TABLERO], char jugador);
char verificarGanador(const char tablero[TAMANO_TABLERO][TAMANO_TABLERO]);
void cambiarJugador(char& jugadorActual);

// --- FUNCIÓN PRINCIPAL (MENÚ) ---

/**
 * @brief Función principal que contiene el bucle del menú.
 */
int main() {

    char opcionMenu;

    do {
        mostrarMenu();
        std::cin >> opcionMenu;

        // Limpiamos el buffer de entrada
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcionMenu) {
        case '1':
            jugarPartida(); // Llama a la función que contiene el juego
            break;
        case '2':
            std::cout << "\nGracias por jugar. ¡Hasta pronto!\n" << std::endl;
            break;
        default:
            std::cout << "\nOpcion NO valida. Intenta de nuevo." << std::endl;
            std::cout << "Presiona Enter para continuar..." << std::endl;
            std::cin.get(); // Pausa para que el usuario lea el error
            break;
        }

    } while (opcionMenu != '2'); // El bucle del menú se repite hasta que elija '2'


    return 0; // El programa termina sin errores
}


// --- IMPLEMENTACIÓN DE FUNCIONES ---

/**
 * @brief Muestra el menú principal del juego en la consola.
 */
void mostrarMenu() {
    // Simula una limpieza de pantalla
    std::cout << "\n\n\n\n\n\n\n\n\n\n";
    std::cout << "===============================\n";
    std::cout << "  BIENVENIDO A TIC-TAC-TOE\n";
    std::cout << "===============================\n";
    std::cout << "1. Jugar Partida\n";
    std::cout << "2. Salir\n";
    std::cout << "===============================\n";
    std::cout << "Elige una opcion: ";
}

/**
 * @brief Ejecuta una partida completa de Tic-Tac-Toe.
 */
void jugarPartida() {
    // --- INICIO DE PARTIDA ---
    char tablero[TAMANO_TABLERO][TAMANO_TABLERO];
    char jugadorActual = JUGADOR_X;
    char ganador = ' ';
    int movimientos = 0;
    bool juegoTerminado = false;

    // 1. Preparar el juego
    inicializarTablero(tablero);
    // --- FIN DE PREPARACIÓN ---

    // 2. Bucle principal del juego
    while (!juegoTerminado) {
        // 2a. Mostrar tablero
        mostrarTablero(tablero);

        // 2b. Pedir y validar jugada
        while (!realizarJugada(tablero, jugadorActual)) {
            // La función realizarJugada ya imprime el error
        }

        // 2c. Incrementar el contador de movimientos
        movimientos++;

        // 2d. Verificar si hay ganador
        ganador = verificarGanador(tablero);
        if (ganador != ' ') {
            juegoTerminado = true;
            mostrarTablero(tablero); // Mostrar el tablero final
            std::cout << "¡FELICIDADES! El Jugador " << ganador << " ha ganado." << std::endl;
        }
        // 2e. Verificar si hay empate
        else if (movimientos == 9) {
            juegoTerminado = true;
            mostrarTablero(tablero); // Mostrar el tablero final
            std::cout << "¡JUEGO TERMINADO! Es un empate." << std::endl;
        }
        // 2f. Si el juego no ha terminado, cambiar de jugador
        else {
            cambiarJugador(jugadorActual);
        }
    } // Fin del bucle while (!juegoTerminado)

    // 3. Pausa antes de volver al menú
    std::cout << "\nPresiona Enter para volver al menu principal..." << std::endl;
    // No necesitamos limpiar el buffer aquí porque la siguiente lectura (cin.get) se encargará de esperar al Enter.
    // Sin embargo, si la última jugada fue inválida, sí necesitamos limpiar.
    // Para estar seguros, lo limpiamos ANTES de esperar el 'get'.
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Este ya está en main
    std::cin.get(); // Espera a que el usuario presione Enter
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
    // Imprimimos saltos de línea para simular una limpieza de pantalla
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
 * @brief Solicita al jugador actual que ingrese su jugada y la valida.
 */
bool realizarJugada(char tablero[TAMANO_TABLERO][TAMANO_TABLERO], char jugador) {
    int eleccion;
    std::cout << "Turno del Jugador " << jugador << ". Elige una casilla (1-9): ";

    // Validación de entrada: Asegura que se ingrese un número
    if (!(std::cin >> eleccion)) {
        std::cout << "Error: Debes ingresar un numero." << std::endl;
        std::cin.clear(); // Limpia el estado de error de cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    // Limpiamos el buffer DESPUÉS de una lectura exitosa (cin >> eleccion)
    // para que el '\n' (Enter) no se quede en el buffer.
    // ESTE ES UN CAMBIO IMPORTANTE para que el cin.get() del menú funcione.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    // Validación de rango
    if (eleccion < 1 || eleccion > 9) {
        std::cout << "Jugada NO valida: Elige un numero entre 1 y 9." << std::endl;
        return false;
    }

    // Mapeo de la elección (1-9) a coordenadas de la matriz (fila, col)
    int fila = (eleccion - 1) / TAMANO_TABLERO;
    int col = (eleccion - 1) % TAMANO_TABLERO;

    // Validación de casilla
    if (tablero[fila][col] == JUGADOR_X || tablero[fila][col] == JUGADOR_O) {
        std::cout << "Jugada NO valida: La casilla ya esta ocupada." << std::endl;
        return false;
    }

    // Si todo es válido, realiza la jugada
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