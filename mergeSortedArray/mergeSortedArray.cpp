#include <vector>
//since nums1 is a vector it can reallocate array with enough space for both array's 
//elements by giving an index. We could copy array into a new var but then we'd have to
//free original. If it were an array of ints with fixed size then we would have to create a
//new array of size m+n
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int endIndex = m + n-1;
        while(m && n)
        {
            if(nums2[n-1] > nums1[m-1])
            {
                nums1[endIndex] = nums2[n-1];
                --n;
            }
            else
            {
                nums1[endIndex] = nums1[m-1];
                --m;
            }
            --endIndex;
        }
        while(n)
        {
            nums1[endIndex] = nums2[n-1];
            --n;
            --endIndex;
        }
    }
};