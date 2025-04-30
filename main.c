// Group Members: Kian Naderi, David Carbajal, Charlton Le, Danny Tran, Lucas Taylor

#include <stdio.h>
#include <stdlib.h>

// Creating block structure
#define block_size 4

struct Block {
    char shape[block_size][block_size];
    int width;
    int height;
};

void printGameRules();
void initializeGameBoard(char gameBoard[20][10]);
void displayGameBoard(char gameBoard[20][10]);
void displayBlock(struct Block b);

struct Block blocks[7] = {
    // Horizontal I
    {{
        {'X', 'X', 'X', 'X'},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    }, 4, 1},

    // T
    {{
        {'X', 'X', 'X', ' '},
        {' ', 'X', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    }, 3, 2},

    // O
    {{
        {'X', 'X', ' ', ' '},
        {'X', 'X', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    }, 2, 2},

    // S
    {{
        {' ', 'X', 'X', ' '},
        {'X', 'X', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    }, 3, 2},

    // L
    {{
        {'X', ' ', ' ', ' '},
        {'X', 'X', 'X', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    }, 3, 2},

    // J
    {{
        {' ', ' ', 'X', ' '},
        {'X', 'X', 'X', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    }, 3, 2},

    // Z
    {{
        {'X', 'X', ' ', ' '},
        {' ', 'X', 'X', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    }, 3, 2}
};


int main() {
    printf("Hello Player! Welcome to Tetris!\n");

    printGameRules();

    // Declare and define the game board
    char gameBoard[20][10] = {0};

    // Initialize and display the board
    initializeGameBoard(gameBoard);
    displayGameBoard(gameBoard);

    printf("\n Example I block:\n");
    displayBlock(blocks[0]);

    // Game loop goes here.
    
    return 0;
}

void printGameRules() {
    printf("Here are the rules of the game:\n");
    printf("Rule #1. Use the arrow keys on your device to move the blocks.\n");
    printf("Rule #2. Press 'q' to quit the game at any time.\n");
    printf("Rule #3. Once a line has been filled in with tetris blocks, that line will be cleared from the board.\n");
    printf("Rule #4: The game ends when any block reaches the top of the board.\n\n");
}

void initializeGameBoard(char gameBoard[20][10]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            gameBoard[i][j] = '.';
        }
    }
}

void displayGameBoard(char gameBoard[20][10]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}

void displayBlock(struct Block b) {
    for (int i = 0; i < b.height; i++) {
        for (int j = 0; j < b.width; j++) {
            if (b.shape[i][j] == 'X') {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}