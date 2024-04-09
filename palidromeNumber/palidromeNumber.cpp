#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        std::string y = std::to_string(x);
        int n = y.size() - 1;
        int m = 0;
        while(m < n){
            if(y[m++] != y[n--])
                return false;
        }
        return true;
    }
};
