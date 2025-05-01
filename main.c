// Group Members: Kian Naderi, David Carbajal, Charlton Le, Danny Tran, Lucas Taylor

#include <stdio.h>
#include <stdlib.h>

// Creating block structure
#define block_size 4

struct Block 
{
    char shape[block_size][block_size];
    int width;
    int height;
};

// Global Variables for the block types
// 
struct Block blocks[7] = 
{
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
// All game functions will be defined here as needed
// Initializes the overall game state (score, level, board, first piece)
void initializeGame(struct GameState *state); 

// spawn new block pieces
// Selects a new random block and places it at the top center of the board.
// Updates the activePiece in the GameState. Returns false if spawn fails (game over).
//  spawnNewPiece(struct GameState *state); 

// Block Representation & Rotation 
// Gets the specific shape definition for a given block type and rotation.
// (This is crucial - the 'blocks' array only holds one rotation)
struct Block getRotatedBlock(int blockIndex, int rotation); 
// Rotates the current active piece (if valid).
void rotatePiece(struct GameState *state);

// --- Collision Detection ---
// Checks if the active piece is in a valid position on the board.
// Considers board boundaries and collisions with existing locked blocks.
// Takes potential new row, col, and the block shape to check.
// bool isValidPosition(const struct GameState *state, const struct Block *piece, int newRow, int newCol);

// Print the rules of the game to console for user's direction
void printGameRules();

// Initializes the game board array (2D array) 
// For now we will pre-defined the game board to be 20 rows and 10 columns
void initializeGameBoard(char gameBoard[20][10]);

// Displays the game board array (2D array) to console
void displayGameBoard(char gameBoard[20][10]);


// Displays a single Tetris block shape to the console (for debugging/example).
// Takes a 'struct Block' as input.
void displayBlock(struct Block b);

// **** NEED TO ADD DIFFERENT USER MOVEMENT FUNCTIONS ****
// LEFT,RIGHT, DOWN, ROTATE, DROP   
// ------------------------------------------------------- Work in Progress ------------------------------------------------------- //






// main function - driver function for the game
// We will call the other functions from here as needed to run the game
int main() 
{
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
    char gameBoard[20][10] = {0};

    // Initialize and display the board
    initializeGameBoard(gameBoard);
    displayGameBoard(gameBoard);

    printf("\n Example I block:\n");
    displayBlock(blocks[0]);

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
}

void initializeGameBoard(char gameBoard[20][10]) 
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            gameBoard[i][j] = '.';
        }
    }
}

void displayGameBoard(char gameBoard[20][10]) 
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}

void displayBlock(struct Block b) 
{
    for (int i = 0; i < b.height; i++) 
    {
        for (int j = 0; j < b.width; j++) 
        {
            if (b.shape[i][j] == 'X') 
            {
                printf("X ");
            } 
            else 
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}