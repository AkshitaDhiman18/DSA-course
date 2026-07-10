#include <climits>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int closest= INT_MAX;
        int final_sum;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++){ //fixed pointer

            int j=i+1; //left pointer
            int k=n-1;  //right pointer
            while(j<k){
                int sum= nums[i]+nums[j]+nums[k];
                if(sum == target){
                    return sum;  //return the exact sum if exists
                }else{
                    int diff= abs(sum-target);
                    if(diff<closest){
                        closest=diff;
                        final_sum=sum;
                    }
                    if(sum<target){  //sum less than target so move left pointer in hope to find either the target or closest sum
                        j++;
                    }else if(sum>target){   //sum more than target so move right pointer in hope to find either the target or closest sum
                        k--;
                    }
                }
            }
        }
        return final_sum; //return the final sum that is closest to target
    }
};