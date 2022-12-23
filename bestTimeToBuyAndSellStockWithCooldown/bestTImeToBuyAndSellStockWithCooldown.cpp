#include <vector>
#include <algorithm>
class Solution {
/**
 * Three ways to solve, tabulations (bottom - up), memoization (top-down/recursion w caching),
 * and state maching.
 * For memoization - https://www.youtube.com/watch?v=I7j0F7AHpb8&ab_channel=NeetCode
 * For state machine - https://www.youtube.com/watch?v=4wNXkhAky3s&ab_channel=TECHDOSE
 * 
 * State Machine Notes: For this problem you can do 3 things on any given day: buy, sell, or rest.
 * Buy State: Is it more profitable to buy today or hold the stock to sell later
 * Sell State: Is it more profitable to sell today or hold the stock for later
 * Skip State: Is it more profitable to have skipped the day before, sold the day before, 
 * or bought, the day before.
 * 
 * The values of the vectors mean:
 * Buy[i] - The the max profits you can have while holding a stock
 * Sell[i] - The max profits you have after selling a stock and holding none
 * Skip[i] - The max profits you have if you did nothing today
 * These state algs become: 
 * Buy = max(skip[i-1] - price, buy[i-1])//buy the stock today because its cheaper, or keep the stock you have. You can only buy after you've rested and to hold a stock is to rest
 * Sell = max(buy[i-1] + price, sell[i-1])//sell the stock today because its higher than if you sold any day before, or keep the day you sold on before today
 * Skip = max(buy[i-1], skip[i-1], sell[i-1]) => sell[i-1]
 * //buy[i-1] is <= skip[i-1] since in order to hold a stock you need to spend money so remove it
 * //skip[i-1] is <= sell[i-1] since selling nets you profit while skipping does nothing
 * 
*/
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<int> buy(n, 0);
        std::vector<int> sell(n,0);
        std::vector<int> skip(n,0);
        buy[0] = -prices[0];
        for(int i = 1; i < n; ++i)
        {
            buy[i] = std::max(skip[i-1]-prices[i], buy[i-1]);
            sell[i] = std::max(buy[i-1] + prices[i],sell[i-1]);
            skip[i] = sell[i-1];
        }
        return std::max(sell[n-1], skip[n-1]);
        
        
    }
};