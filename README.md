# Terminal Chess Game 🎮

A classic game of chess implemented from scratch in C++ for the terminal.

This project was developed as a part of Umar's Programming Fundamentals course (passed in 2023) during his BS(AI) degree at FAST National University.

## Table of Contents 📜

- [Project Title & Badges](#project-title--badges)
- [Description](#description)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Installation](#installation)
- [Usage](#usage)
- [How to Use](#how-to-use)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Important Links](#important-links)
- [Footer](#footer)

## Project Title & Badges 🏅

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Terminal](https://img.shields.io/badge/Terminal-black?style=for-the-badge&logo=xterm)

## Description 📝

This project is a terminal-based implementation of the game of Chess, built entirely in C++. It provides a command-line interface for playing chess, allowing two players to take turns making moves. The game initializes with a standard chess board setup and validates moves according to chess rules. The goal is to provide a functional chess game that can be played directly in a terminal environment.

## Features ✨

- **Full Chess Game Implementation:** Supports all standard chess pieces (King, Queen, Rook, Bishop, Knight, Pawn) with their respective movement rules.
- **Terminal-Based Interface:** Playable entirely through a text-based console interface.
- **Two-Player Mode:** Designed for two players to compete against each other on the same machine.
- **Move Validation:** Basic validation to ensure moves adhere to chess rules for each piece.
- **Board Representation:** Visual representation of the chessboard with pieces displayed using standard characters.
- **Turn-Based Gameplay:** Alternating turns for White and Black.

## Tech Stack 💻

- **Language:** C++
- **Environment:** Terminal/Command Line

## Installation 🚀

This project is a single C++ source file and does not have external dependencies beyond a standard C++ compiler.

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/umarahmed1218/terminal-chess-game.git
    cd terminal-chess-game
    ```

2.  **Compile the code:**
    You will need a C++ compiler (like g++).
    ```bash
    g++ chess.cpp -o terminal_chess
    ```

## Usage 🕹️

To start a game, run the compiled executable from your terminal.

```bash
./terminal_chess
```

The game will then display the chessboard and prompt players to enter their moves.

## How to Use 💡

The game is turn-based, with White starting first.

1.  **Board Display:** The game will display an 8x8 chessboard with row numbers (1-8) and column letters (a-h).
2.  **Piece Selection:** When it's your turn, you will be prompted to enter the current position of the piece you want to move (e.g., `Row #` then `Column`).
    - Example input: `Row # 2` and `Column e` for the white pawn on e2.
3.  **Move Input:** After selecting a piece, you will be asked for the desired destination for that piece (e.g., `Row #` then `Column`).
    - Example input: `Row # 4` and `Column e` to move the pawn from e2 to e4.
4.  **Move Validation:** The game will attempt to validate your move based on the selected piece's rules. Invalid moves will result in a prompt to try again.
5.  **Capturing Pieces:** If your move lands on a square occupied by an opponent's piece, that piece is captured.
6.  **Winning the Game:** The game ends when a King is captured (checkmate is not explicitly implemented, but capturing the King ends the game).

**Example Gameplay Snippet:**

```

<-- White's Turn -->

Postion of piece you would like to move:
Row # 2
Column: e

Where would you like to move it? 
Row # 4
Column: e
```

## Project Structure 📁

- `README.md`: This documentation file.
- `chess.cpp`: The main C++ source file containing the entire game logic.
- `.DS_Store`: macOS system file (ignored).

## Footer 👋

**Repository:** `terminal-chess-game`
**URL:** [https://github.com/umarahmed1218/terminal-chess-game](https://github.com/umarahmed1218/terminal-chess-game)
**Author:** [umarahmed1218](https://github.com/umarahmed1218)

--- 
