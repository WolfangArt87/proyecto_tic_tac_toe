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

/**
 * @brief Inicializa el tablero con números del 1 al 9.
 * @param tablero Matriz 3x3 que representa el tablero de juego.
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
 * @param tablero El tablero de juego (const para no modificarlo).
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
 * @param tablero El tablero de juego (se modifica si la jugada es válida).
 * @param jugador El caracter del jugador actual ('X' u 'O').
 * @return true si la jugada fue válida y realizada, false si fue inválida.
 */
bool realizarJugada(char tablero[TAMANO_TABLERO][TAMANO_TABLERO], char jugador) {
    int eleccion;
    std::cout << "Turno del Jugador " << jugador << ". Elige una casilla (1-9): ";

    // Validación de entrada: Asegura que se ingrese un número
    if (!(std::cin >> eleccion)) {
        std::cout << "Error: Debes ingresar un numero." << std::endl;
        std::cin.clear(); // Limpia el estado de error de cin
        // Descarta la entrada incorrecta del buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    // Validación de rango: Asegura que esté entre 1 y 9
    if (eleccion < 1 || eleccion > 9) {
        std::cout << "Jugada NO valida: Elige un numero entre 1 y 9." << std::endl;
        return false;
    }

    // Mapeo de la elección (1-9) a coordenadas de la matriz (fila, col)
    int fila = (eleccion - 1) / TAMANO_TABLERO; 
    int col = (eleccion - 1) % TAMANO_TABLERO; 

    // Validación de casilla: Asegura que no esté ocupada
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
 * @param tablero El tablero de juego.
 * @return El caracter del ganador ('X' u 'O') o un espacio (' ') si no hay ganador.
 */
char verificarGanador(const char tablero[TAMANO_TABLERO][TAMANO_TABLERO]) {
    // 1. Verificar Filas
    for (int i = 0; i < TAMANO_TABLERO; ++i) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            return tablero[i][0]; // Retorna 'X' o 'O'
        }
    }

    // 2. Verificar Columnas
    for (int j = 0; j < TAMANO_TABLERO; ++j) {
        if (tablero[0][j] == tablero[1][j] && tablero[1][j] == tablero[2][j]) {
            return tablero[0][j];
        }
    }

    // 3. Verificar Diagonal Principal (izquierda a derecha)
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        return tablero[0][0];
    }

    // 4. Verificar Diagonal Secundaria (derecha a izquierda)
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        return tablero[0][2];
    }

    // Si no hay ganador
    return ' ';
}

/**
 * @brief Cambia el turno del jugador.
 * @param jugadorActual Referencia al jugador actual (se modifica).
 */
void cambiarJugador(char& jugadorActual) {
    if (jugadorActual == JUGADOR_X) {
        jugadorActual = JUGADOR_O;
    } else {
        jugadorActual = JUGADOR_X;
    }
}

/**
 * @brief Función principal que contiene el bucle del juego.
 */
int main() {
    
    char jugarDeNuevo; // Variable para controlar el reinicio

    do { // Bucle exterior para jugar de nuevo
        
        // --- INICIO DE RESET DE PARTIDA ---
        // Se declaran aquí para reiniciarse en cada nueva partida.
        char tablero[TAMANO_TABLERO][TAMANO_TABLERO];
        char jugadorActual = JUGADOR_X;
        char ganador = ' ';
        int movimientos = 0;
        bool juegoTerminado = false;

        // 1. Preparar el juego
        inicializarTablero(tablero);
        // --- FIN DE RESET DE PARTIDA ---


        // 2. Bucle principal del juego (Bucle de una partida)
        while (!juegoTerminado) {
            // 2a. Mostrar tablero
            mostrarTablero(tablero);

            // 2b. Pedir y validar jugada
            while (!realizarJugada(tablero, jugadorActual)) {
                // La función realizarJugada ya imprime el error
                // y limpiamos el buffer, así que solo reintentamos.
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

        // 3. Preguntar si desea jugar de nuevo
        std::cout << "\n¿Desean jugar de nuevo? (s/n): ";
        std::cin >> jugarDeNuevo;

        // Limpiamos el buffer para evitar que la siguiente
        // lectura de std::cin falle si el usuario escribió "si" o algo más.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S'); // Condición de reinicio


    // 4. Despedida final
    std::cout << "\nGracias por jugar. Presiona Enter para salir." << std::endl;
    std::cin.get();    // Espera a que el usuario presione Enter
    
    return 0; // El programa termina sin errores
}