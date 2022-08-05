/*
Runtime: 5 ms, faster than 84.88% of C online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 6.9 MB, less than 37.52% of C online submissions for Best Time to Buy and Sell Stock II.
*/
int maxProfit(int* prices, int pricesSize){
    int totalProfit = 0;

    for(int i = 0 ; i < pricesSize - 1 ; i++) {
        if(prices[i] < prices[i + 1])
            totalProfit += prices[i + 1] - prices[i];
    }

    return totalProfit;
}
