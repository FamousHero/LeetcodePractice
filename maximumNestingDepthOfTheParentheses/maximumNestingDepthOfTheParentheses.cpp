#include <stack>
#include <string>
/**
 * Intuitive answer
 * Wrong since we aren't decrementing depth with each pop. Gives total amount
 * of () found.
 * FIX: increase depth on push and decrease depth on pop. Separates amount of ()
 * from nested ().

class Solution {
public:
    int maxDepth(string s) {
        if(s.size() == 0)
            return 0;
        if(s.size() == 1 && s.find(')') == -1 && s.find('(') == -1)
            return 0;
        int maxDepth = 0;
        std::stack<char> paraStack;
        int depth = 0;
        for(char& c: s)
        {
            if(c == '(')
                
            {
                if(paraStack.empty())
                    depth = 0;
                paraStack.push(c);
                //FIX: ++depth;
            }
            else if(c == ')')
            {
                paraStack.pop();
                //not worth including algo lib just for 1 function
                maxDepth = maxDepth > depth + 1? maxDepth: depth + 1; //FIX: maxDepth > depth? maxDepth: depth;
                //--depth;
            }
            else
                continue;
        }
        return maxDepth;
    }
};
*/

/**
 * Similar to above answer but cleaner. Depth is already being tracked by the stack size
 * so just use that to generate maxDepth (ans)
*/
class Solution {
public:
    int maxDepth(std::string s) {
        int ans = 0;

        std::stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                st.pop();
            }
            
            ans = std::max(ans, (int)st.size()); //guess algorithm lib included already
        }
        
        return ans;
    }
};

/**
 * Optimal solution. Since input string will always be formatted correctly and 
 * only need to match brackets, its possible to use a counter instead of a stack.
 * Intuition: we are really just using the stack to track its size, so whenever
 * we would push to the stack, just increment the counter. Whenever we would pop,
 * decrement the counter. 
 * class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int openBrackets = 0;

        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else if (c == ')') {
                openBrackets--;
            }
            
            ans = max(ans, openBrackets);
        }
        
        return ans;
    }
};
*/