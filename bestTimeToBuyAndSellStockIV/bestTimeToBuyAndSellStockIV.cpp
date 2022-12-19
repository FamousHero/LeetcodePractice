#include <vector>
#include <algorithm>
#include <iostream>
class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
     std::vector<std::vector<int>> transactions(k+1, std::vector<int>(prices.size(), 0)); //extra row since 
        //first row is 0 transactions
        //std::cout << transactions.size();
        for(int i = 1; i < transactions.size(); ++i) // i is amount of transactions possible
        {
            int maxDiff = -prices[0];
            for(int j = 1; j < transactions[0].size(); ++j) //j is the current day
            {
                transactions[i][j] = std::max(transactions[i][j-1], (prices[j] + maxDiff));
                maxDiff = std::max(maxDiff, (transactions[i-1][j] - prices[j]));
            }
        }
        return transactions[k][prices.size()-1];
    }
};