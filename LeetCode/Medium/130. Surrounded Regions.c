void check(char ** board, int row, int col, int x, int y) {
    if(x < 0 || y < 0 || x >= row || y >= col || board[x][y] == 'X')
        return;
    if(board[x][y] == 'O') {
        board[x][y] = '1';
        check(board, row, col, x + 1, y);
        check(board, row, col, x - 1, y);
        check(board, row, col, x, y + 1);
        check(board, row, col, x, y - 1);
    }
}

void solve(char** board, int boardSize, int* boardColSize){
    for(int i = 0 ; i < boardSize ; i++) {
        if(board[i][0] == 'O')
            check(board, boardSize, *boardColSize, i, 0);
        if(board[i][(*boardColSize) - 1] == 'O')
            check(board, boardSize, *boardColSize, i, (*boardColSize) - 1);
    }

    for(int j = 1 ; j < (*boardColSize) - 1 ; j++) {
        if(board[0][j] == 'O')
            check(board,boardSize,*boardColSize,0, j);
        if(board[boardSize - 1][j] == 'O')
            check(board,boardSize, *boardColSize, boardSize - 1, j);
    }

    for(int i = 0 ; i < boardSize ; i++) {
        for(int j = 0 ; j < *boardColSize ; j++)
        {
            if(board[i][j] == '1')
                board[i][j] = 'O';
            else
                board[i][j] = 'X';
        }
    }
}
