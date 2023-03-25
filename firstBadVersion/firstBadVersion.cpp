// The API isBadVersion is defined for you.


//This version is to avoid errors in editor
 bool isBadVersion(int version){
    return false;
 };

class Solution {
public:
    int firstBadVersion(int n) {
        for(int i = 1; i <= n; ++i)
        {
            if(isBadVersion(i))
                return i;
            if(!isBadVersion(n))
                return n+1;
            --n;
        }
        return n+1;
    }
};