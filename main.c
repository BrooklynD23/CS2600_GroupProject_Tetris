#define _DEFAULT_SOURCE

// Group Members: Kian Naderi, David Carbajal, Charlton Le, Danny Tran, and Lucas Taylor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Necessary for UNIX system calls - Cite: https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <string.h>


// Creating block structure
#define block_size 4


struct Block
{
    char shapes[4][block_size][block_size];
    int widths[4];
    int heights[4];
};

// Global Variables for the block types
// We used csourcecodes.blogspot.com/2016/06/tetris-game-c-program-block-game.html. svedev0. to help us make the blocks
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
                {'X',' ',' ',' '},
                {'X',' ',' ',' '},
                {'X',' ',' ',' '},
                {'X',' ',' ',' '}
            },
            {
                {'X','X','X','X'},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {'X',' ',' ',' '},
                {'X',' ',' ',' '},
                {'X',' ',' ',' '},
                {'X',' ',' ',' '}
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
                        // as block shape data is directly accessed via blocks[blockIndex].shapes[rotation]
};

struct GameState {
    char gameBoard[20][10];
    struct currentPiece activePiece;
    int score;
    int level;
    int linesClearedTotal;
    int gameOver;
};

// Function Prototypes
void initializeGameBoard(char gameBoard[20][10]);
void spawnNewPiece(struct GameState *gameState);
int validPosition(char gameBoard[20][10], int blockIndex, int rotation, int row, int col);
void printGameRules();
void displayBlock(struct Block b, int rotation); // For debugging purposes, not used in main game loop
void displayGameBoard(const struct GameState *gameState);
int clearLines(struct GameState *gameState);
void moveLeft(struct GameState *gameState);
void moveRight(struct GameState *gameState);
void moveDown(struct GameState *gameState);
void rotate(struct GameState *gameState);
void drop(struct GameState *gameState);
void clearScreen();
void init_terminal_nonblocking(void);
void reset_terminal(void);
int linux_kbhit(void);
char linux_getch(void);
void applyGravity(struct GameState *gameState);


// All game functions will be defined here as needed
// Initializes the overall game state (score, level, board, first piece)
void initializeGame(struct GameState *gameState) {
    gameState->score = 0;
    gameState->level = 1;
    gameState->linesClearedTotal = 0;
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
    state->activePiece.col = (10 - blocks[index].widths[rotation]) / 2; // Use board width 10

    if (!validPosition(state->gameBoard, index, rotation,
                       state->activePiece.row, state->activePiece.col)) {
        // printf("Game Over!\n"); // Game over message is handled in main
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

                // Check board boundaries
                if (r < 0 || r >= 20 || c < 0 || c >= 10) return 0; // piece is out of bounds
                // Check collision with existing pieces on the board
                if (gameBoard[r][c] == 'X') return 0; // collision with another block
            }
        }
    }
    return 1; // Position is valid
}


// Print the rules of the game to console for user's direction
// void printGameRules(); // Definition is later

// Initializes the game board array (2D array)
// void initializeGameBoard(char gameBoard[20][10]); // Definition is later

// Displays the game board array (2D array) to console
// void displayGameBoard(const struct GameState *gameState); // Definition is later


// Displays a single Tetris block shape to the console (for debugging/example).
// Takes a 'struct Block' as input.
// void displayBlock(struct Block b, int rotation); // Definition is later

// Clears full lines in the game board and shifts the rows down.
// Returns the number of lines cleared.
// int clearLines(struct GameState *gameState); // Definition is later

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
        // Lock the piece in place
        for (int i = 0; i < blocks[gameState->activePiece.blockIndex].heights[gameState->activePiece.rotation]; i++) {
            for (int j = 0; j < blocks[gameState->activePiece.blockIndex].widths[gameState->activePiece.rotation]; j++) {
                if (blocks[gameState->activePiece.blockIndex].shapes[gameState->activePiece.rotation][i][j] == 'X') {
                    int board_r = gameState->activePiece.row + i;
                    int board_c = gameState->activePiece.col + j;
                    // Ensure we only write within bounds, though validPosition should prevent out-of-bounds row/col for activePiece itself
                    if (board_r >= 0 && board_r < 20 && board_c >=0 && board_c < 10) {
                        gameState->gameBoard[board_r][board_c] = 'X';
                    }
                }
            }
        }
        clearLines(gameState);
        spawnNewPiece(gameState); // This will set gameOver if spawning fails
    }
}

void rotate(struct GameState *gameState) 
{
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

    // Lock the piece in place (same logic as in moveDown's else block)
    for (int i = 0; i < blocks[gameState->activePiece.blockIndex].heights[gameState->activePiece.rotation]; i++) {
        for (int j = 0; j < blocks[gameState->activePiece.blockIndex].widths[gameState->activePiece.rotation]; j++) {
            if (blocks[gameState->activePiece.blockIndex].shapes[gameState->activePiece.rotation][i][j] == 'X') {
                 int board_r = gameState->activePiece.row + i;
                 int board_c = gameState->activePiece.col + j;
                 if (board_r >= 0 && board_r < 20 && board_c >=0 && board_c < 10) {
                    gameState->gameBoard[board_r][board_c] = 'X';
                }
            }
        }
    }
    clearLines(gameState);
    spawnNewPiece(gameState); // This will set gameOver if spawning fails
}

void clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}



// Until main(): 
// We referenced: https://www.geeksforgeeks.org/kbhit-c-language/

// Global variables for terminal settings
static struct termios old_tio, new_tio;

// Initialize new terminal i/o settings
void init_terminal_nonblocking(void) {
    tcgetattr(STDIN_FILENO, &old_tio);          // Save old terminal settings
    new_tio = old_tio;                          // Copy old settings to new settings
    new_tio.c_lflag &= ~(ICANON | ECHO);        // Disable canonical mode (line buffering) and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio); // Apply new settings
}

// Restore old terminal i/o settings
void reset_terminal(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio); // Restore old settings
}
int linux_kbhit(void)
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0; // Don't wait
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

char linux_getch(void)
{
    char ch = 0;
    ssize_t n = read(STDIN_FILENO, &ch, 1);
    if (n < 0)
    {
        perror("read error");
        return 0;
    }
    return ch;
}

// main function - driver function for the game
// We will call the other functions from here as needed to run the game
int main() {
    srand(time(NULL));
    init_terminal_nonblocking(); // Setup terminal for non-blocking input

    struct GameState gameState;
    initializeGame(&gameState);

    // No initial "Hello PLAYERS" here, printGameRules handles first screen
    printGameRules(); // Waits for Enter

    // Initial display after rules
    clearScreen();
    displayGameBoard(&gameState); // Pass address of gameState

    // MAIN GAME LOOP
    while (!gameState.gameOver) {
        // INPUT HANDLING
        if (linux_kbhit()) {
            char input = linux_getch();

            // Check for valid input and process it
            // We use a switch-case for better readability
            switch (input) {
                case 'a': case 'A': moveLeft(&gameState); break;
                case 'd': case 'D': moveRight(&gameState); break;
                case 's': case 'S': moveDown(&gameState); break; 
                case 'w': case 'W': rotate(&gameState); break;
                case ' ': drop(&gameState); break;             
                case 'q': case 'Q': gameState.gameOver = 1; break;
            }
            if (!gameState.gameOver) { // Refresh screen only if input was processed and game not over
                clearScreen();
                displayGameBoard(&gameState); // Pass address of gameState
            } else {
                // If game over happened due to moveDown/drop, we might want one last draw
                // before the final game over screen, or just let the loop exit.
                // The current logic in moveDown/drop will call spawnNewPiece, which sets gameOver.
                // The loop condition will then be false.
                // The final game over screen is handled *after* the loop.
            }
        }

        // GRAVITY TICK
        if (!gameState.gameOver) { // Double check game over before gravity
            int base_tick_interval_us = 500000; // Microseconds (0.5 seconds initially)
            int level_speed_decrease_us = 25000;
            int gravity_interval_us = base_tick_interval_us - ((gameState.level -1) * level_speed_decrease_us); // Level 1 has base speed

            if (gravity_interval_us < 50000) { // Max speed: 0.05 seconds
                gravity_interval_us = 50000;
            }

            static clock_t last_gravity_time = 0;
            if (last_gravity_time == 0) last_gravity_time = clock(); // Initialize on first pass

            clock_t current_time = clock();
            double time_elapsed_ms = ((double)(current_time - last_gravity_time) / CLOCKS_PER_SEC) * 1000.0;

            if (time_elapsed_ms > (gravity_interval_us / 1000.0) ) { // Convert gravity_interval_us to ms
                moveDown(&gameState); // This can lead to gameOver
                if (!gameState.gameOver) {
                    clearScreen();
                    displayGameBoard(&gameState); // Pass address of gameState
                }
                last_gravity_time = current_time;
            }

            usleep(10000); // Sleep for 10ms to reduce CPU polling
        }
    }

    reset_terminal(); // Restore terminal settings before exiting

    clearScreen();
    printf("\n\n    *****************\n");
    printf("    * G A M E   O V E R *\n");
    printf("    *****************\n\n");
    printf("    Final Score: %d\n", gameState.score);
    printf("    Final Level: %d\n", gameState.level);
    printf("    Lines Cleared: %d\n\n", gameState.linesClearedTotal);
    printf("    Thanks for playing!\n\n");

    return 0;
}

// Function to print the game rules to the console
void printGameRules()
{
    clearScreen(); // Clear previous output before printing rules
    printf("Here are the rules of the game:\n");
    printf("Rule #1. Use 'A'(Left), 'D'(Right), 'S'(Down), 'W'(Rotate) keys to move blocks.\n");
    printf("         Use 'SPACE' to drop the block instantly.\n");
    printf("Rule #2. Press 'Q' to quit the game at any time.\n");
    printf("Rule #3. Once a line has been filled, it will be cleared, and you score points.\n");
    printf("Rule #4: The game ends when a new block cannot be placed at the top.\n\n");
    printf("Good luck and have fun!\n\n");
    printf("Press Enter to start...\n");

    // Wait for Enter key press in non-blocking mode
    char c;
    do {
        if (linux_kbhit())
        { // Check if a key is pressed
            c = linux_getch(); // Read the key
            // Check for Enter (LF for most Unix-like, CR might also be sent by some terminals/Enter key)
            if (c == '\n' || c == '\r')
            {
                break;
            }
        }
         usleep(10000); // Small delay to prevent busy-waiting and reduce CPU usage
    } while (1);
    // printf("\n\n"); // Removed extra newlines, clearScreen will handle fresh screen
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

void displayGameBoard(const struct GameState *gameState)
{
    char displayBuffer[20][10];
    int i, j;

    // Copy the current board state to a temporary buffer
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 10; j++)
        {
            displayBuffer[i][j] = gameState->gameBoard[i][j];
        }
    }

    // Overlay the active piece onto the buffer if the game is not over
    if (!gameState->gameOver) // Though display is usually called when not game over, this is a safe check
    {
        // It's important that activePiece is valid here. If game just ended by spawnNewPiece failure,
        // activePiece might be in an invalid state for drawing.
        // However, spawnNewPiece sets gameOver = 1, so this block shouldn't execute if piece is bad.
        struct currentPiece piece = gameState->activePiece;
        // No need for currentBlockType, access directly: blocks[piece.blockIndex]

        for (int r_block = 0; r_block < blocks[piece.blockIndex].heights[piece.rotation]; r_block++)
        {
            for (int c_block = 0; c_block < blocks[piece.blockIndex].widths[piece.rotation]; c_block++)
            {
                if (blocks[piece.blockIndex].shapes[piece.rotation][r_block][c_block] == 'X')
                {
                    int board_r = piece.row + r_block;
                    int board_c = piece.col + c_block;
                    // Ensure the piece part is within board boundaries before drawing
                    if (board_r >= 0 && board_r < 20 && board_c >= 0 && board_c < 10)
                    {
                        displayBuffer[board_r][board_c] = 'X'; // Overlay the block on the display buffer
                    }
                }
            }
        }
    }

    // Print Score and Level
    printf("Score: %d   Level: %d   Lines: %d\n", gameState->score, gameState->level, gameState->linesClearedTotal);
    printf("----------------------\n"); // 10 cells * 2 chars/cell ("X ") = 20 chars. Add 2 for borders.

    // Print the board from the buffer
    for (i = 0; i < 20; i++)
    {
        printf("|"); // Left border
        for (j = 0; j < 10; j++)
        {
            printf("%c ", displayBuffer[i][j]); // Print char and a space
        }
        printf("|\n"); // Right border and newline
    }
    printf("----------------------\n"); // Footer
    printf("Controls: A(Left) D(Right) S(Down) W(Rotate) SPACE(Drop) Q(Quit)\n");
}

void displayBlock(struct Block b, int rotation) {
    for (int i = 0; i < block_size; i++) { // Use block_size as loop bound
        for (int j = 0; j < block_size; j++) { // Use block_size as loop bound
            // Check if i and j are within the actual height/width for this rotation to avoid printing excess spaces
            // For simplicity, this original version prints the full 4x4 grid.
            printf("%c ", b.shapes[rotation][i][j]); // Removed ternary, just print the char
        }
        printf("\n");
    }
}

int clearLines(struct GameState *gameState)
{
    int linesClearedThisTurn = 0;
    // Scoring: 0 lines: 0, 1 line: 100, 2 lines: 300, 3 lines: 500, 4 lines (Tetris): 800
    // Score is multiplied by the current level.
    const int scoreMap[] = {0, 100, 300, 500, 800}; // Index = number of lines cleared

    for (int row = 19; row >= 0; /* row is managed inside */) {
        int isFull = 1;
        for (int col = 0; col < 10; col++) {
            if (gameState->gameBoard[row][col] != 'X') {
                isFull = 0;
                break;
            }
        }

        if (isFull) {
            linesClearedThisTurn++;
            // Shift all rows above this one down
            for (int i = row; i > 0; i--) {
                for (int col = 0; col < 10; col++) {
                    gameState->gameBoard[i][col] = gameState->gameBoard[i-1][col];
                }
            }
            // Clear the top row
            for (int col = 0; col < 10; col++) {
                gameState->gameBoard[0][col] = '.';
            }
            // Don't decrement 'row' here, so we re-check the current row index
            // as it now contains the content of the row that was above.
        } else {
            row--; // Row was not full, move to check the one above.
        }
    }

    if (linesClearedThisTurn > 0)
    {
        // Update score
        if (linesClearedThisTurn <= 4) { // Max 4 lines can be cleared at once
            gameState->score += scoreMap[linesClearedThisTurn] * gameState->level;
        }

        // Update total lines cleared
        gameState->linesClearedTotal += linesClearedThisTurn;

        // Update level - e.g., new level every 10 lines
        // Level up when (total lines / lines per level) gives a new integer quotient
        // greater than or equal to current level -1 (or just compare total lines to next threshold)
        int linesPerLevel = 20; // Example: 10 lines to level up
        int nextLevelThreshold = gameState->level * linesPerLevel;

        if (gameState->linesClearedTotal >= nextLevelThreshold && gameState->level < 50) // Cap level at 50
        {
            gameState->level++;
        }
    }

    return linesClearedThisTurn;
}
