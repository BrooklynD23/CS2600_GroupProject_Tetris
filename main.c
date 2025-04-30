// Group Members: Kian Naderi, David Carbajal, Charlton Le, Danny Tran, and Lucas Taylor

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void initializeGameBoard(char gameBoard[20][10]);
void displayGameBoard(char gameBoard[20][10]);

int main() {
    printf("Hello Player! Welcome to Tetris!\n");

    // Declare and define the game board
    char gameBoard[20][10] = {0};

    // Initialize and display the board
    initializeGameBoard(gameBoard);
    displayGameBoard(gameBoard);

    // Placeholder for game loop
    // Game loop would go here.
    

    return 0;
}

void initializeBoard(char gameBoard[20][10]) {
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