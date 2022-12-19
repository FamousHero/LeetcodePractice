#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxProfit = 0;
        int lowestPrice = prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] < lowestPrice)
                lowestPrice = prices[i];
            else if(prices[i] - lowestPrice > maxProfit)
                maxProfit = prices[i] - lowestPrice;
            
        }
        return maxProfit;
    }
};