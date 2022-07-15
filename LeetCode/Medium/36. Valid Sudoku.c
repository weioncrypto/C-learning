bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int sum = 0;    // 用來記錄值
    int tmp[9] = {0};
    
    //  先針對橫行觀察
    for(int i = 0 ; i < 9 ; i++)
    {
        
        memset(tmp, 0 , sizeof(tmp));
        for(int j = 0 ; j < 9 ; j++){
            if(board[i][j] == '.')continue;
            tmp[board[i][j] - 49]++;
            if(tmp[board[i][j] - 49] > 1)return false;
        }
    }
    // 直行
    printf("\n");
    for(int i = 0 ; i < 9 ; i++)
    {
        memset(tmp, 0 , sizeof(tmp));
        for(int j = 0 ; j < 9 ; j++){
            if(board[j][i] == '.')continue;
            tmp[board[j][i] - 49]++;
            if(tmp[board[j][i] - 49] > 1)return false;
        }
    }
    
    printf("\n");
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            memset(tmp, 0 , sizeof(tmp));
            for(int a = i*3 ; a < i*3 + 3 ; a++)
            {
                for(int b = j*3 ; b < j*3 + 3;b++)
                {
                    if(board[a][b] == '.')continue;
                    tmp[board[a][b] - 49]++;
                    if(tmp[board[a][b] - 49] > 1)return false;
                }
            }

        }
    }
    

    return true;
}
