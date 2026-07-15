class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        //Approach 1: Brute force approach
        //taken extra space
        /*vector<int> nums;
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
        return median;*/

        //Approach 2: Better solution with constant sc
        int m= nums1.size();
        int n= nums2.size();

        int total= m+n; //total size
        int i=0;
        int j=0;
        int pos1, pos2, poss;  //leftmidpos, rightmidpos, midpos

        //for even no of observations
        pos1= total/2;
        pos2= (total/2)+1;
        //for odd no of observations
        poss= (total+1)/2;

        int count=0;
        int val;
        int f_mid=0, s_mid=0, mid=0;  //leftmedian , rightmedian, medianelement
        double median;

        while(i<m || j<n){
            if(j == n || (i<m && nums1[i] <= nums2[j])){
                val= nums1[i];
                i++;
            }else{
                val= nums2[j];
                j++;
            }
            count++;

            if(total % 2 == 0){
                if(count == pos1) f_mid= val;
                if(count == pos2){
                    s_mid= val;
                median= (double)(f_mid+s_mid)/2;
                return median;
                }
            }else if(total % 2 != 0){
                if(count == poss){
                    mid= val;
                    median= double(mid);
                    return median;
                }
            }
        }
       return 0.0;
    }
};