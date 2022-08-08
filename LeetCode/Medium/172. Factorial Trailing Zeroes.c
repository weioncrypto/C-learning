/*
Runtime: 10 ms, faster than 16.00% of C online submissions for Factorial Trailing Zeroes.
Memory Usage: 5.4 MB, less than 100.00% of C online submissions for Factorial Trailing Zeroes.
*/
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int trailingZeroes(int n){
    int num_five = 0;
    while (n > 0)
    {
        int tmp = n;
        //  檢驗 5 成分
        while (tmp % 5 == 0) {
            num_five++;
            tmp /= 5;
        }
        
        n--;
    }
    return num_five;
}



Runtime: 0 ms, faster than 100.00% of C online submissions for Factorial Trailing Zeroes.
Memory Usage: 5.5 MB, less than 64.00% of C online submissions for Factorial Trailing Zeroes.
*/
int trailingZeroes(int n){
    return n/5 + n/25 + n/125 + n/625 + n/3125; 
}
