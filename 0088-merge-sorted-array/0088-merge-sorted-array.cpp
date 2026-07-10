#include <algorithm>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i= n-1;   //pointer 1 points to last index of nums2
        int j= m-1; //pointer 2 points to last non zero index of nums1
        int k= (m+n)-1; //pointer 3 points to last index to nums1 also this pointer is used to write elments od nums2 in nums1 in correct order by satisfying conditions using i and j

        while(i>=0 && j>=0){
            if(nums1[j] > nums2[i]){
                nums1[k] = nums1[j];
                k--;
                j--;
            }else if(nums1[j] <= nums2[i]){
                nums1[k] = nums2[i];
                k--;
                i--;
            }
        }
        while(i>=0){  //if element left in nums2 then simply merge them
            nums1[k]= nums2[i];
            k--;
            i--;
        }
        return;
    }
};

//Why are we starting from the end instead of the beginning?
/* "Because nums1 ke end mein empty space available hai. Agar front se merge karenge to existing elements ko baar-baar shift karna padega. End se merge karne par hum directly sabse bada element uski final position par rakh dete hain, isliye shifting ki zarurat nahi padti aur algorithm O(m+n) mein complete ho jata hai."*/