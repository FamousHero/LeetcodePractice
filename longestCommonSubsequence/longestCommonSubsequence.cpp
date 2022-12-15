#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        /* DP since we need to keep track of the biggest subseq found as we interate through
         * https://youtu.be/ASoaQq66foQ?t=795
        */
        const int m=text1.size(),n=text2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1));
        //to find lcs one string needs to be contiguous while the other can have spacing
        for(int i=0;i<m+1;i++){
            dp[i][0]=0; //first column is for alg to work with starting letter (OOB index error without it) and base case is empty string
        }
        for(int i=0;i<n+1;i++){
            dp[0][i]=0; //first row is for alg to work with starting letter (OOB index error without it) and base case is empty string
        }
        // each cell is the answer to subproblem where text1 = text1[0:i] and text2 = text2[0:j] 
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
               if(text1[i-1]==text2[j-1]){ //check if the current letter match, 
                  dp[i][j]= 1+dp[i-1][j-1]; //if they do add 1 to the subproblem solution if the letter was removed from both strings
               }else{
                   dp[i][j]= std::max(dp[i-1][j],dp[i][j-1]);
               } 
            }
        }
        return dp[m][n];
    }
};