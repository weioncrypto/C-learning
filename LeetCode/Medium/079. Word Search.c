void dfs(char **board, int boardSize, int boardColSize, int i, int j,char *word, bool *find) {

    if(*word == '\0')
        (*find) = true;
    if(i < 0 || i >= boardSize || j < 0 || j >= boardColSize)
        return;
    if(board[i][j] != *word)
        return;
    
    char backTrack = board[i][j];
    board[i][j] = ' ';
    
    dfs(board,boardSize, boardColSize, i - 1, j, word + 1, find);
    dfs(board,boardSize, boardColSize, i + 1, j, word + 1, find);
    dfs(board,boardSize, boardColSize,i , j - 1, word + 1, find);
    dfs(board,boardSize, boardColSize,i , j + 1, word + 1, find);

    board[i][j] = backTrack;

    return;   
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    bool find = false;
    for(int i = 0 ; i < boardSize ; i++) {
        for(int j = 0 ; j < (*boardColSize) ; j++) {
            if(board[i][j] == *word)
                dfs(board, boardSize, *boardColSize, i , j, word, &find);
        }
    }
    return find;
}
