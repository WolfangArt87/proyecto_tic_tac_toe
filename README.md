# 🐱 Proyecto: Tic-Tac-Toe (Juego del Gato)

Este es un proyecto universitario para la materia de Programación Dinámica. Es una implementación del clásico juego "Tic-Tac-Toe" desarrollado en C++ y ejecutado en la consola.

El programa cumple con todos los requisitos básicos del juego, permitiendo a dos jugadores competir en una misma terminal.

## 🎓 Información Académica

- **Materia:** Programación Dinámica
- **Docente:** Dr. Herman Geovany Ayala Zúñiga
- **Alumno:** Wolfang Arturo García Méndez

---

## 🚀 Características

- **Juego de 2 Jugadores:** Permite a dos jugadores (X y O) competir por turnos.
- **Detección de Ganador:** El sistema identifica automáticamente una victoria por fila, columna o diagonal.
- **Detección de Empate:** El juego termina en empate si el tablero se llena sin un ganador.
- **Validación de Entradas:** El programa previene jugadas inválidas:
  - No permite ingresar letras o símbolos (solo números).
  - No permite elegir casillas fuera del rango (1-9).
  - No permite sobrescribir una casilla ya ocupada.
- **Código Modular:** El código está organizado en funciones para una fácil lectura y mantenimiento.
- **Ligero:** No requiere librerías externas, solo la biblioteca estándar de C++ (`iostream` y `limits`).

---

## ⚙️ ¿Cómo compilar y ejecutar?

Este programa está escrito en C++ estándar.

### Requisitos

- Un compilador de C++ (como G++, Clang, o el compilador de Visual Studio).

### 1\. Compilación (Línea de Comandos)

Abre una terminal, navega a la carpeta donde se encuentra el archivo `main.cpp` y ejecuta:

```bash
# Compilar el programa
g++ main.cpp -o TicTacToe
```

_(Si tu archivo se llama diferente, reemplaza `main.cpp`)_

### 2\. Ejecución

Una vez compilado, puedes ejecutar el juego:

- **En Windows:**
  ```bash
  .\TicTacToe.exe
  ```
- **En macOS/Linux:**
  ```bash
  ./TicTacToe
  ```

---

## 🎮 ¿Cómo jugar?

1.  Al iniciar el programa, se mostrará un tablero vacío con casillas numeradas del 1 al 9.
2.  El Jugador 1 (X) comienza.
3.  Ingresa el número de la casilla donde deseas colocar tu 'X' y presiona `Enter`.
4.  El tablero se actualizará y será el turno del Jugador 2 (O).
5.  El juego continúa hasta que un jugador gane o el tablero se llene (empate).
