#include <vector>
#include <string>

class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        std::string newS;
        int spaceIndex = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(spaceIndex == spaces.size()) //if we've added all the spaces, copy the rest of the std::string to the newS and return it
            {
                newS.append(s.begin()+i, s.end());
                s = newS;
                return s;
            }
            if(i == spaces[spaceIndex])
            {
                newS += " ";
                ++spaceIndex;
            }
            newS += s[i];
        }
        s = newS;
        return s;
    }
};