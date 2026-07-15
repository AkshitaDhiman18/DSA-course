class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        //Approach 1: Brute force approach

        vector<int> nums;
        int i=0;
        int j=0;
        double median;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] <nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }else if(nums1[i] >= nums2[j]){
                nums.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()){
            nums.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()){
            nums.push_back(nums2[j]);
            j++;
        }
        
        int n= nums.size();

        if(n % 2 == 0){
            int first= nums[n/2-1];
            int second= nums[n/2];

            double val= double(first + second);
            median= val/2;
        }else{
            int val= nums[n/2];
            median= double(val);
        }
        return median;
    }
};