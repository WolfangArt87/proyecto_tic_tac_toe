# 🐱 Proyecto: Tic-Tac-Toe (Juego del Gato)

Este es un proyecto universitario para la materia de Programación Dinámica. Es una implementación del clásico juego "Tic-Tac-Toe" desarrollado en C++ y ejecutado en la consola.

El programa ha sido mejorado para incluir un menú principal, múltiples modos de juego y un oponente de IA (CPU).

## 🎓 Información Académica

* **Materia:** Programación Dinámica
* **Docente:** Dr. Herman Geovany Ayala Zúñiga
* **Alumno:** Wolfang Arturo García Méndez

---

## 🚀 Características

* **Menú Principal Interactivo:** Un menú en consola para navegar entre los modos de juego o salir.
* **Dos Modos de Juego:**
    * **Humano vs. Humano:** El modo clásico para que dos jugadores compitan en la misma terminal.
    * **Humano vs. CPU:** ¡Reta a la máquina! El jugador humano (X) se enfrenta a una IA (O).
* **IA (CPU) Sencilla:** El CPU opera con una lógica de 3 pasos para decidir su movimiento:
    1.  **Ganar:** Si tiene un movimiento para ganar, lo toma.
    2.  **Bloquear:** Si el jugador está a punto de ganar, lo bloquea.
    3.  **Aleatorio:** Si no puede ganar ni bloquear, elige una casilla al azar.
* **Detección de Ganador y Empate:** El sistema identifica automáticamente una victoria por fila, columna o diagonal, así como los empates.
* **Validación de Entradas:** El programa previene jugadas inválidas (letras, números fuera de rango, casillas ocupadas).
* **Código Modular:** El código está organizado en funciones claras (`mostrarMenu`, `jugarPartidaPvP`, `jugarPartidaCPU`, `realizarJugadaCPU`, etc.).

---

## ⚙️ ¿Cómo compilar y ejecutar?

Este programa está escrito en C++ moderno y utiliza características del estándar C++11.

### Requisitos

* Un compilador de C++ (como G++, Clang, o el compilador de Visual Studio).
* El compilador debe ser compatible con **C++11** o superior (debido al uso de `<thread>` y `<chrono>` para la pausa de la IA).

### 1. Compilación (Línea de Comandos)

Abre una terminal, navega a la carpeta donde se encuentra el archivo `main.cpp` y ejecuta:

```bash
# Compilar el programa (requiere C++11)
g++ -std=c++11 main.cpp -o TicTacToe
