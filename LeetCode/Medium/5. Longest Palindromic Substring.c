/*
Runtime: 444 ms, faster than 15.86% of C online submissions for Longest Palindromic Substring.
Memory Usage: 118.5 MB, less than 5.07% of C online submissions for Longest Palindromic Substring.
*/
char * longestPalindrome(char * s){
    int n = strlen(s);
    int max_length = 1;
    int x = 0, y = 0;

    // 初始化dp矩陣
    bool** dp = (bool**)malloc(sizeof(bool*) * n);
    for(int i = 0 ; i < n ; i++){
        dp[i] = (bool*)malloc(sizeof(bool) * n);
        memset(dp[i],false,n);
    }
    

    // 確認字串s中i~j的值是否為回文
    // 是則紀錄並比較最大長度
    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = i ; j <= n - 1 ; j++){
            if(i == j)dp[i][j] = true;
            else if(s[i] == s[j]){
                if(j - i == 1)
                    dp[i][j] = true;         // 相鄰字串一定為回文
                else
                    dp[i][j] = dp[i+1][j-1]; // 若非相鄰則dp檢查
            }

            if(dp[i][j] && j - i >= max_length){
                max_length = j - i + 1;
                x = i;
                y = j;
            }
        }
    }    

    // 分配記憶體以回傳結果
    char* ret = (char*)malloc(sizeof(char) * (max_length + 1));
    memcpy(ret, s+x, max_length);
    ret[max_length] = '\0';
    return ret;
}
