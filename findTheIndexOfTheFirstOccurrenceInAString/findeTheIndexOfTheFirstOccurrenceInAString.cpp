#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int size_m = haystack.size();
        for(int i = 0; i < size_m; ++i){
            if(haystack[i] == needle[0]){
                int j = 0;
                while(i < size_m && j < needle.size() && haystack[i] == needle[j]){
                    ++i; ++j;
                    continue;
                }
                if(j == needle.size()){
                    return i -j;
                }
                i -= j;
            }
        }
        return -1;
    }
};