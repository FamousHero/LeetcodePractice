#include <string>
#include <queue>
/**
 * Intuition: * can be ( or ) or "" so just keep count of paren occurances
 * If ( > 1 then make it ), if ) and we have a *, make it (
 * 
 * ISSUE: does not account for case "*(". We have to do the same thing 
 * but in reverse. Can be accomplished with a 2nd for loop or having two counts,
 * one for left-side and one for right-side, if one side reaches < 0, then string is invalid.
 * 
--------------Original Attempt------------------
class Solution {
public:
    bool checkValidString(std::string s) {
        int free = 0;
        std::queue<char> leftParen;
        for(char c: s)
        {
            if(c == '(')
            {
                leftParen.push(c);
            }
            else if(c == '*')
                ++free;
            else
            {
                if(!leftParen.empty())
                    leftParen.pop();
                else if(free > 0)
                    --free;
                else
                    return false;
            }
        }
        if(leftParen.size() > free)
            return false;
        return true;
    }
};

----------------LeetCode Solution-----------------------
*/
class Solution {
public:
    bool checkValidString(std::string s) {
        int openCount = 0;
        int closeCount = 0;
        int length = s.length() - 1;
        
        // Traverse the string from both ends simultaneously
        for (int i = 0; i <= length; i++) {
            // Count open parentheses or asterisks
            if (s[i] == '(' || s[i] == '*') {
                openCount++;
            } else {
                openCount--;
            }
            
            // Count close parentheses or asterisks
            if (s[length - i] == ')' || s[length - i] == '*') {
                closeCount++;
            } else {
                closeCount--;
            }
            
            // If at any point open count or close count goes negative, the string is invalid
            if (openCount < 0 || closeCount < 0) {
                return false;
            }
        }
        
        // If open count and close count are both non-negative, the string is valid
        return true;
    }
};
