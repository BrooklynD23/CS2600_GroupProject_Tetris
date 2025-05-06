// Group Members: Kian Naderi, David Carbajal, Charlton Le, Danny Tran, and Lucas Taylor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Creating block structure
#define block_size 4

struct Block
{
    char shapes[4][block_size][block_size];
    int widths[4];
    int heights[4];
};

// Global Variables for the block types
//
struct Block blocks[7] = {
    // I
    {
        .shapes = {
            {
                {'X','X','X','X'},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X',' ',' '},
                {' ','X',' ',' '},
                {' ','X',' ',' '},
                {' ','X',' ',' '}
            },
            {
                {'X','X','X','X'},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X',' ',' '},
                {' ','X',' ',' '},
                {' ','X',' ',' '},
                {' ','X',' ',' '}
            }
        },
        .widths = {4, 1, 4, 1},
        .heights = {1, 4, 1, 4}
    },

    // T
    {
        .shapes = {
            {
                {'X','X','X',' '},
                {' ','X',' ',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X',' ',' '},
                {'X','X',' ',' '},
                {' ','X',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X',' ',' '},
                {'X','X','X',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X',' ',' '},
                {' ','X','X',' '},
                {' ','X',' ',' '},
                {' ',' ',' ',' '}
            }
        },
        .widths = {3, 2, 3, 2},
        .heights = {2, 3, 2, 3}
    },

    // O
    {
        .shapes = {
            {
                {' ','X','X',' '},
                {' ','X','X',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X','X',' '},
                {' ','X','X',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X','X',' '},
                {' ','X','X',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X','X',' '},
                {' ','X','X',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            }
        },
        .widths = {2, 2, 2, 2},
        .heights = {2, 2, 2, 2}
    },

    // S
    {
        .shapes = {
            {
                {' ','X','X',' '},
                {'X','X',' ',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {'X',' ',' ' ,' '},
                {'X','X',' ' ,' '},
                {' ','X',' ' ,' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X','X',' '},
                {'X','X',' ',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {'X',' ',' ' ,' '},
                {'X','X',' ' ,' '},
                {' ','X',' ' ,' '},
                {' ',' ',' ',' '}
            }
        },
        .widths = {3, 2, 3, 2},
        .heights = {2, 3, 2, 3}
    },

    // Z
    {
        .shapes = {
            {
                {'X','X',' ',' '},
                {' ','X','X',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X',' ' ,' '},
                {'X','X',' ' ,' '},
                {'X',' ',' ' ,' '},
                {' ',' ',' ',' '}
            },
            {
                {'X','X',' ',' '},
                {' ','X','X',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X',' ' ,' '},
                {'X','X',' ' ,' '},
                {'X',' ',' ' ,' '},
                {' ',' ',' ',' '}
            }
        },
        .widths = {3, 2, 3, 2},
        .heights = {2, 3, 2, 3}
    },

    // J
    {
        .shapes = {
            {
                {'X','X','X',' '},
                {' ',' ','X',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','X',' ' ,' '},
                {' ','X',' ' ,' '},
                {'X','X',' ' ,' '},
                {' ',' ',' ',' '}
            },
            {
                {'X',' ',' ',' '},
                {'X','X','X',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {'X','X',' ' ,' '},
                {'X',' ',' ' ,' '},
                {'X',' ',' ' ,' '},
                {' ',' ',' ',' '}
            }
        },
        .widths = {3, 2, 3, 2},
        .heights = {2, 3, 2, 3}
    },

    // L
    {
        .shapes = {
            {
                {'X','X','X',' '},
                {'X',' ',' ',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {'X','X',' ' ,' '},
                {' ','X',' ' ,' '},
                {' ','X',' ' ,' '},
                {' ',' ',' ',' '}
            },
            {
                {' ',' ','X',' '},
                {'X','X','X',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {'X',' ',' ' ,' '},
                {'X',' ' ,' ' ,' '},
                {'X','X',' ' ,' '},
                {' ',' ',' ',' '}
            }
        },
        .widths = {3, 2, 3, 2},
        .heights = {2, 3, 2, 3}
    }
};


// Structure to represent the currently active Tetris piece
struct currentPiece
{
    int blockIndex;     // Index into the global 'blocks' array (0-6) to know which shape it is
    int rotation;       // Current rotation state (e.g., 0, 1, 2, 3) - needed for rotation logic
    int row;            // Current row position of the top-left corner of the block's 4x4 grid on the game board
    int col;            // Current column position of the top-left corner of the block's 4x4 grid on the game board
    struct Block currentShape; // The actual shape data for the current rotation (we'll need a function to get this)
};


// ------------------------------------------------------- Work in Progress ------------------------------------------------------- //
struct GameState {
    char gameBoard[20][10];
    struct currentPiece activePiece;
    int score;
    int level;
    int gameOver;
};

void initializeGameBoard(char gameBoard[20][10]);
void spawnNewPiece(struct GameState *gameState);
int validPosition(char gameBoard[20][10], int blockIndex, int rotation, int row, int col);


// All game functions will be defined here as needed
// Initializes the overall game state (score, level, board, first piece)
void initializeGame(struct GameState *gameState) {// Example - Assuming GameState struct exists elsewhere
    gameState->score = 0;
    gameState->level = 1;
    gameState->gameOver = 0;

    initializeGameBoard(gameState->gameBoard);
    spawnNewPiece(gameState);
}

// spawn new block pieces
// Selects a new random block and places it at the top center of the board.
// Updates the activePiece in the GameState. Returns false if spawn fails (game over).
void spawnNewPiece(struct GameState *state) {
    int index = rand() % 7;
    int rotation = 0;

    state->activePiece.blockIndex = index;
    state->activePiece.rotation = rotation;
    state->activePiece.row = 0;
    state->activePiece.col = (10 - blocks[index].widths[rotation]) / 2;

    if (!validPosition(state->gameBoard, index, rotation,
                       state->activePiece.row, state->activePiece.col)) {
        printf("Game Over!\n");
        state->gameOver = 1;
                       }
}

// --- Collision Detection ---
// Checks if the active piece is in a valid position on the board.
// Considers board boundaries and collisions with existing locked blocks.
// Takes potential new row, col, and the block shape to check.
int validPosition(char gameBoard[20][10],int blockIndex, int rotation, int row, int col) {
    for (int i = 0; i < blocks[blockIndex].heights[rotation]; i++) {
        for (int j = 0; j < blocks[blockIndex].widths[rotation]; j++) {
            if (blocks[blockIndex].shapes[rotation][i][j] == 'X') {
                int r = row + i;
                int c = col + j;

                if (r >= 20 || c < 0 || c >= 10) return 0;
                if (gameBoard[r][c] == 'X') return 0;
            }
        }
    }
    return 1;
}

// Block Representation & Rotation


// Rotates the current active piece (if valid).
// void rotatePiece(struct GameState *state); // Example

// Print the rules of the game to console for user's direction
void printGameRules();

// Initializes the game board array (2D array)
// For now we will pre-defined the game board to be 20 rows and 10 columns
void initializeGameBoard(char gameBoard[20][10]);

// Displays the game board array (2D array) to console
void displayGameBoard(char gameBoard[20][10]);


// Displays a single Tetris block shape to the console (for debugging/example).
// Takes a 'struct Block' as input.
void displayBlock(struct Block b, int rotation);

// **** NEED TO ADD DIFFERENT USER MOVEMENT FUNCTIONS ****
// LEFT,RIGHT, DOWN, ROTATE, DROP
// Examples
void moveLeft(struct GameState *gameState) {
    if (validPosition(gameState->gameBoard, gameState->activePiece.blockIndex,
                     gameState->activePiece.rotation,
                     gameState->activePiece.row,
                     gameState->activePiece.col - 1)) {
        gameState->activePiece.col--;
    }
}

void moveRight(struct GameState *gameState) {
    if (validPosition(gameState->gameBoard, gameState->activePiece.blockIndex,
                     gameState->activePiece.rotation,
                     gameState->activePiece.row,
                     gameState->activePiece.col + 1)) {
        gameState->activePiece.col++;
    }
}

void moveDown(struct GameState *gameState) {
    if (validPosition(gameState->gameBoard, gameState->activePiece.blockIndex,
                     gameState->activePiece.rotation,
                     gameState->activePiece.row + 1,
                     gameState->activePiece.col)) {
        gameState->activePiece.row++;
    } else {
        // Lock the piece in place and spawn a new one
        for (int i = 0; i < blocks[gameState->activePiece.blockIndex].heights[gameState->activePiece.rotation]; i++) {
            for (int j = 0; j < blocks[gameState->activePiece.blockIndex].widths[gameState->activePiece.rotation]; j++) {
                if (blocks[gameState->activePiece.blockIndex].shapes[gameState->activePiece.rotation][i][j] == 'X') {
                    gameState->gameBoard[gameState->activePiece.row + i][gameState->activePiece.col + j] = 'X';
                }
            }
        }
        spawnNewPiece(gameState);
    }
}

void rotate(struct GameState *gameState) {
    int newRotation = (gameState->activePiece.rotation + 1) % 4;

    if (validPosition(gameState->gameBoard, gameState->activePiece.blockIndex,
                     newRotation,
                     gameState->activePiece.row,
                     gameState->activePiece.col)) {
        gameState->activePiece.rotation = newRotation;
    }
}

void drop(struct GameState *gameState) {
    while (validPosition(gameState->gameBoard, gameState->activePiece.blockIndex,
                        gameState->activePiece.rotation,
                        gameState->activePiece.row + 1,
                        gameState->activePiece.col)) {
        gameState->activePiece.row++;
    }

    for (int i = 0; i < blocks[gameState->activePiece.blockIndex].heights[gameState->activePiece.rotation]; i++) {
        for (int j = 0; j < blocks[gameState->activePiece.blockIndex].widths[gameState->activePiece.rotation]; j++) {
            if (blocks[gameState->activePiece.blockIndex].shapes[gameState->activePiece.rotation][i][j] == 'X') {
                gameState->gameBoard[gameState->activePiece.row + i][gameState->activePiece.col + j] = 'X';
            }
        }
    }
    spawnNewPiece(gameState);
}
// ------------------------------------------------------- Work in Progress ------------------------------------------------------- //

// main function - driver function for the game
// We will call the other functions from here as needed to run the game
int main()
{
    srand(time(NULL));

     // --- Game Loop Placeholder ---
    // This is where the main logic of the game will reside:
    // 1. Spawning new blocks
    // 2. Handling user input (moving/rotating blocks)
    // 3. Automatically moving the block down
    // 4. Checking for collisions
    // 5. Locking blocks in place
    // 6. Checking for and clearing completed lines
    // 7. Updating the score
    // 8. Checking for game over condition
    // 9. Updating the display
    // This loop will continue until the game over condition is met or the user quits.

    printf("Hello Player! Welcome to Tetris!\n");

    printGameRules();

    // Declare and define the game board
    char gameBoard[20][10] = {0}; // Initialize to zeros (or nulls)

    // Initialize and display the board
    initializeGameBoard(gameBoard);
    displayGameBoard(gameBoard);

    //will delete later, just making sure we are printing the correct shapes
    printf("\n Example I block:\n");
    displayBlock(blocks[0], 0);
    displayBlock(blocks[0], 1);
    displayBlock(blocks[0], 2);
    displayBlock(blocks[0], 3);
    // Display the first block (I piece) as an example

    // Game loop goes here.

    // Game Over & Summary of User's Score
    printf("\n--- GAME OVER ---\n");
    // printf("Final Score: %d\n", gameState.score);  <- Need to set-up gameState struct
    // printf("Final Level: %d\n", gameState.level);

    return 0;
}

void printGameRules()
{
    printf("Here are the rules of the game:\n");
    printf("Rule #1. Use the arrow keys on your device to move the blocks.\n");
    printf("Rule #2. Press 'q' to quit the game at any time.\n");
    printf("Rule #3. Once a line has been filled in with tetris blocks, that line will be cleared from the board.\n");
    printf("Rule #4: The game ends when any block reaches the top of the board.\n\n");
    printf("Good luck and have fun!\n\n");
    printf("Press any key to continue...\n");
    getchar(); // Wait for user input to continue
    printf("\n\n");
}

// Renamed from initializeBoard (main) to initializeGameBoard (Testing) for consistency
void initializeGameBoard(char gameBoard[20][10])
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            gameBoard[i][j] = '.'; // Use '.' for empty cells
        }
    }
}

void displayGameBoard(char gameBoard[20][10])
{
    // Consider adding top/bottom borders or line numbers for clarity
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}
//Will delete later, just making sure we are printing the correct shapes
void displayBlock(struct Block b, int rotation) {
    for (int i = 0; i < block_size; i++) {
        for (int j = 0; j < block_size; j++) {
            printf("%c ", b.shapes[rotation][i][j] == 'X' ? 'X' : '.');
        }
        printf("\n");
    }
}