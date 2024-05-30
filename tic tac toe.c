#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];
int currentPlayer;

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard() {
    printf("\n");
    printf("  1 2 3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("  -----\n");
        }
    }
    printf("\n");
}

// Function to check if the current player has won
int checkWin() {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full
int checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int main() {
    initializeBoard();
    currentPlayer = 1;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 (X) - Player 2 (O)\n");

    int row, col;

    while (1) {
        printBoard();

        printf("Player %d's turn. Enter row and column (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        board[row - 1][col - 1] = (currentPlayer == 1) ? 'X' : 'O';

        if (checkWin()) {
            printBoard();
            printf("Player %d wins!\n", currentPlayer);
            break;
        }

        if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}
