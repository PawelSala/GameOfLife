# GameOfLife
## Introduction
This program simulates Conway's Game of Life, a cellular automaton devised by John Horton Conway in 1970. The game evolves over a grid of cells that can be alive (O) or dead (.), updating based on specific rules.

## Features
- Customizable grid size (rows and columns)
- Customizable number of starting points (initial live cells)
- Automatic evolution of the grid based on the Game of Life rules
- The game stops when it reaches a stable state

## Compilation
To compile the program, run the following command:  
` g++ -o game_of_life main.cpp `
## Running the Program
To run the program, use the following command:  
` ./game_of_life `

## Instructions
1. Run the program and enter the number of rows, columns, and starting points when prompted.
2. Watch the simulation as the grid updates each iteration until a stable state is reached.
3. End of the game: The game prints "Game finished" when done.

## Example
Default values are:  
`How many rows: 20`  
`How many columns: 40`  
`How many starting points: 50`
