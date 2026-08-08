#include <climits>
#include <cmath>
class Solution {
public:
    bool ispossible(vector<int>& nums, int divisor, int threshold){
        int n= nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+= ceil((double) nums[i]/divisor);
        }
        if(sum <= threshold) return true;
        return false;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int max_divisor= INT_MIN;

        //search space
        for(int i=0; i<n; i++){
            max_divisor= max(max_divisor, nums[i]);
        }
        //brutforce approch
        /*for(int divisor=1; divisor<=max_divisor; divisor++){
            bool value= ispossible(nums, divisor, threshold);

            if(value == true) return divisor;
        }*/
        //binary search
        int s=1, e= max_divisor;
        int ans=-1;

        while(s<=e){
            int mid= s+(e-s)/2;

            bool value= ispossible(nums, mid, threshold);
            

            if(value == true){
                ans= mid;
                e=mid-1;
            }else if(value == false){
                s=mid+1;
            }
        }
        return ans;
    }
};