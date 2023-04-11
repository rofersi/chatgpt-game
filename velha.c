#include <stdio.h>

void display_board(char board[][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int check_win(char board[][3], char symbol) {
    int i, j;
    // Check horizontal rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return 1;
    }
    // Check vertical columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
            return 1;
    }
    // Check diagonal
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return 1;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return 1;
    return 0;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int row, col;
    char symbol = 'X';
    int num_moves = 0;
    printf("JOGO DA VELHA\n\n");
    display_board(board);
    while (num_moves < 9) {
        printf("Jogador %c, insira a linha (0-2) e coluna (0-2) separados por um espaco: ", symbol);
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Jogada invalida. Insira valores entre 0 e 2.\n");
            continue;
        }
        if (board[row][col] != ' ') {
            printf("Essa posicao ja esta ocupada. Escolha outra.\n");
            continue;
        }
        board[row][col] = symbol;
        num_moves++;
        display_board(board);
        if (check_win(board, symbol)) {
            printf("Jogador %c venceu!\n", symbol);
            return 0;
        }
        symbol = (symbol == 'X') ? 'O' : 'X';
    }
    printf("Fim do jogo. Empate!\n");
    return 0;
}
