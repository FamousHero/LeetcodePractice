#include <vector>
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        char temp;
        int sSize = s.size()-1;
        for(int i = 0; i < s.size()/2; ++i, --sSize)
        {
            temp = s[i];
            s[i] = s[sSize];
            s[sSize] = temp;
        }
    }
};