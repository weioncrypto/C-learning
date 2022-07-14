/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Pow(x, n).
Memory Usage: 5.5 MB, less than 84.67% of C online submissions for Pow(x, n).
*/
double myPow(double x, int n){
    if(n == 0)return 1;
    if(x == 1)return 1;
    x = (n > 0) ? x : 1 / x;

    double ret = x;
    long long note = n;
    note = (note < 0) ? -note : note;

    long long count = 1;
    double tmp;

    while (count < note)
    {
        tmp = ret * ret;
        ret = tmp;
        count = count * 2;
    }

    for(long long i = note ; i < count ; i++){
        tmp = ret / x;
        ret = tmp;
    }    
    
    return ret;
}
