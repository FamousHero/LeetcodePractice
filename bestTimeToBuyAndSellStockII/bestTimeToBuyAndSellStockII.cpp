#include <vector>
class Solution {
    /**
     * For this problem its a running profit, this means that instead of looking for the max peak and min valley
     * We want to buy when the stock starts to increase and sell when it starts to decrease.
     * This means for every day it increases, we add the difference between to current day and the day before
     * and for every day it decreases we do nothing. Think of this algorithm as every day it increases,
     * we subtract the day before from our profit (buy the stock the day before) and 
     * add today to our profit (sell it today) - so technically selling and buying on the same day!!!
     * If we couldn't buy and sell on the same day then we do 3 while loops
     * while(i < days)
     *  while prices[i] >= prices[i+1]{++i}//find the valley
     *  buy = prices[i];
     *  while prices[i] <= prices[i+1]{++i}//find the peak
     *  profit += prices[i] - buy
     * return profit
     * both are O(n) 
     * 
     * DP/state machine solution - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/803206/PythonJSJavaGoC%2B%2B-O(n)-by-DP-Greedy-%2B-Visualization 
    */
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] > prices[i-1])//if you're making a profit
                profit += prices[i] - prices[i-1];
        }
        return profit;

    }
};