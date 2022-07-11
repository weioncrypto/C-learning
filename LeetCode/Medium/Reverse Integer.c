/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Reverse Integer.
Memory Usage: 5.8 MB, less than 9.72% of C online submissions for Reverse Integer.
*/
int reverse(int x){
    if(x == INT32_MIN || x == INT32_MAX)return 0;
    long long ret = 0;
    int count = 0;
    int temp = (x >= 0) ? x : -x;
    while (temp >= 1)
    {
        count++;
        temp /= 10;
    }

    temp = (x >= 0) ? x : -x;
    while (temp >= 1)
    {
        ret += (temp % 10)*pow(10, count - 1);
        temp /= 10;
        count--;
    }

    if(ret > INT32_MAX || ret < INT32_MIN)return 0;
    return ((x >= 0)?(int)ret:-(int)ret);
}



// 試圖減少空間複雜度(但沒改善)
// 利用每次迴圈提前檢查邊界條件實作
/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Reverse Integer.
Memory Usage: 5.8 MB, less than 9.72% of C online submissions for Reverse Integer.
*/
int reverse(int x){
    int ret = 0;  //輸出結果
    while (x != 0)
    {
        if(ret > INT32_MAX/10 || ret < INT32_MIN/10)return 0;
        else if(ret == INT32_MAX/10 || ret == INT32_MIN/10){
            if(ret%10 == 7 || ret %10 < -8)return 0;
        }
        ret = ret*10 + x%10;

        x /= 10;
    }
    return ret;
}
