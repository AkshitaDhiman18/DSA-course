#include <climits>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int closest= INT_MAX;
        int final_sum;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum= nums[i]+nums[j]+nums[k];
                if(sum == target){
                    return sum;
                }else{
                    int diff= abs(sum-target);
                    if(diff<closest){
                        closest=diff;
                        final_sum=sum;
                    }
                    if(sum<target){
                        j++;
                    }else if(sum>target){
                        k--;
                    }
                }
            }
        }
        return final_sum;
    }
};