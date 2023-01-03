#include <vector>
#include <string>
//Time Complexity: O(m*n) => matrix traversal since for each word we check each letter
class Solution {
public:
    int minDeletionSize(std::vector<std::string>& strs) {
        int deleteColumns = 0;
        for(int i = 0; i < strs[0].size(); ++i){
            for(int j = 1; j < strs.size(); ++j)
            {
                if(strs[j-1][i] > strs[j][i])
                {
                    ++deleteColumns;
                    break;
                }
            }
        }
        return deleteColumns;
    }
};