#include <vector>
//since nums1 is a vector it can reallocate array with enough space for both array's 
//elements by giving an index. We could copy array into a new var but then we'd have to
//free original. If it were an array of ints with fixed size then we would have to create a
//new array of size m+n
class Solution {
public:
    //Sorted in non-decreasing order
    // ie. nums1 [1,1,2,3,4,4] nums2 [1,5,6,6,8,23]
    
    // m = nums1.size() n = nums2.size()
    
    //return merged_nums = [1,1,2,3,4,4,5,6,...]
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m; --n; // Set m & n to last index in each array
        while(m >= 0 && n >= 0){
            if(nums1[m] > nums2[n]){
        //nums1[m+n+1] = nums1[m--] does not work
        //compiler calculates righthand side first to get value
        //so left hand side is really nums1[(m-1)+n+1] where the -1 
        //is implicit
                nums1[m+n+1] = nums1[m];
                --m;
            }
            else{
                nums1[m+n+1] = nums2[n];
                --n;
            }
        }       
        //One will have already reached its end
        //So only 1 for loop will run
        /*
         * if m > 0, its already sorted, literally
         * nums1[m] == nums1[m]
        for(;m>=0;m--){
            nums1[m] = nums1[m];
        }
        */
        for(;n>=0;n--){
            nums1[n] = nums2[n];
        }
    }
};
    }
};
