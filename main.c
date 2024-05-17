#include <stdio.h>
#define c 3
#define r 4

int count_Live_neighbors(int board[c][r], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < c && j >= 0 && j < r && !(i == row && j == col)) {
                count += board[i][j];
            }
        }
    }

    return count;
}

void game_life(int board[c][r]) {
    int nextBoard[c][r];
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            int liveNeighbors = count_Live_neighbors(board, i, j);

            if (board[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    nextBoard[i][j] = 0;
                } else {
                    nextBoard[i][j] = 1;
                }
            } else {
                if (liveNeighbors == 3) {
                    nextBoard[i][j] = 1;
                } else {
                    nextBoard[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            board[i][j] = nextBoard[i][j];
        }
    }
}
void test() {
    int board[c][r] = {{0, 1, 0},{0, 0, 1},{1, 1, 1},{0, 0, 0}};
    game_life(board);
    int check[c][r] = {{0, 0, 0},{1, 0, 1},{0, 1, 1},{0, 1, 0}};
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            if (board[i][j] != check[i][j])
                printf("Matrices are different\n");

}
int main() {
    test();
}