### Connect Four Game in C

### Overview
This repository contains a simple Connect Four game written in C language. In this game, two players alternate turns to drop one of their discs into a column of their choosing, and the first player to get four discs in a row, either horizontally, vertically, or diagonally, wins the game.

### How to Play
1. Compile and run the program.
2. Players will take turns to input a column number where they wish to drop their token.
3. The game board will be displayed after every move.
4. The game will declare a winner when one player gets four of their discs in a row or declare a draw if the board is full.
5. The user can choose to replay the game or quit.

### Code Structure
- **Struct Node:** Represents a node containing the player and column information.
- **Struct SList:** Represents a singly linked list holding the moves played.
- **Function createList():** Initializes and returns a new list.
- **Function insertNode():** Inserts a new node into the list.
- **Function replay():** Replays the moves stored in the list.
- **Function freeList():** Frees up the allocated memory.
- **Function InMove():** Takes the column input from the user.
- **Function InToken():** Inserts the token into the chosen column.
- **Function nospace():** Checks if there is space in the chosen column.
- **Function checkWin():** Checks if the current player has won.
- **Function isDraw():** Checks if the game is a draw.
- **Function main():** Orchestrates the game flow and handles user inputs.

### Important Notes
- The program uses standard libraries like `<stdio.h>`, `<stdlib.h>`, and `<stdbool.h>` to manage inputs/outputs and memory allocation.
- The program implements a singly linked list to store the moves and replay them.
  
### Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "slist.h"

#define ROW 6
#define COL 7

int main() {
    // ... main game loop ...
    return 0;
}
```

### Compilation
To compile the program, you can use the following command (assuming `gcc` is installed):
```sh
gcc main.c slist.c -o connectFour 
```

Here, `main.c` and `slist.c` are the filenames of your C code. Run the generated executable `connectFour` to play the game.
```sh
./connectFour
```

### Running the Game
- Follow the on-screen prompts to input your moves.
- The game will declare a winner or a draw accordingly.
- Choose to replay or quit the game when prompted.
