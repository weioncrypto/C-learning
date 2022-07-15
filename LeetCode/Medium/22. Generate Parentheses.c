void dfs(char* base, char*** ret,int* rs, int n,int openCount,int closeCount, int count){
    if(openCount == closeCount && closeCount == n)
    {
        // 配對成功，分配記憶體並按 base 填入 ret
        (*rs)++;
        (*ret) = realloc(*ret, sizeof(char*) * (*rs));
        (*ret)[(*rs) - 1] = calloc(1, sizeof(char) * (2 * n + 1));
        for(int i = 0 ; i <= 2*n ; i++)
        {
            (*ret)[(*rs) - 1][i] = base[i];
        }
        return;
    }
    else
    {
        // 尚未配對完全
        if(openCount < n){
            base[count] = '(';
            dfs(base, ret, rs, n, openCount + 1, closeCount, count+1);
            base[count] = '\0';
        }

        if(closeCount < openCount){
            base[count] = ')';
            dfs(base, ret, rs, n, openCount, closeCount + 1, count+1);
            base[count] = '\0';
        }
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char** ret = (char**)calloc(1,sizeof(char*));
    char* base = calloc(2*n + 1,sizeof(char));
    *returnSize = 0;
    dfs(base, &ret, returnSize, n, 0 ,0 ,0);
    return ret;
}
