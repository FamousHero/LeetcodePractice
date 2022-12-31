#include <vector>
#include <iostream>
#include <algorithm>
class Solution {
    /** Difficult problem: key is to realize you need to find the best two transactions
     *  This means testing each possible transaction and keeping track. <-- When you see this that means DP problem
     *  The rows are the transactions possible while the columns are the days. Each day check
     *  whether you should not do a tranaction on this day (you wont yield more profit) or you should
     *  IMPORTANT: you can only do 1 transactions at a time ie. sell before you buy
     *  
     * https://youtu.be/oDhu5uGq_ic?t=802
    */

public:
        int maxProfit(std::vector<int>& prices) {
        std::vector<std::vector<int>> transactions(3, std::vector<int>(prices.size(), 0));
        //std::cout << transactions.size();
        for(int i = 1; i < transactions.size(); ++i) // i is amount of transactions possible
        {
            int maxDiff = -prices[0];
            for(int j = 1; j < transactions[0].size(); ++j) //j is the current day
            {
                transactions[i][j] = std::max(transactions[i][j-1], (prices[j] + maxDiff));//dont do a transaction today or do one
                maxDiff = std::max(maxDiff, (transactions[i-1][j] - prices[j]));//maxDiff is the difference between your max Profit and buying a stock
                //the best maxDiff means the day in which even after buying the days stock, you have the biggest profit 
            }
        }
        return transactions[2][prices.size()-1];
    }
};