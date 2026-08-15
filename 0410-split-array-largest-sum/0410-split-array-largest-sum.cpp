#include<climits>
class Solution {
public:
    bool isvalid(vector<int>& nums, int k, int mid){
        int size= nums.size();
        int sum=0;
        int count=1;

        for(int i=0; i<size; i++){
            if(sum+nums[i] <= mid){
                sum=sum+nums[i];
            }else if(sum+nums[i] > mid){
                count++;
                if(nums[i] > mid || count > k){
                    return false;
                }else{
                    sum= nums[i];
                }
            }
        }

        if(count <= k) return true;
        return false;

    }
    int splitArray(vector<int>& nums, int k) {
        int size= nums.size();
        //search space
        if(size < k) return -1;

        int minrange= INT_MIN;
        int maxrange=0;
        for(int i=0; i<size; i++){
            minrange= max(minrange, nums[i]);
            maxrange+=nums[i];
        }

        int s= minrange;
        int e= maxrange;
        int ans=-1;

        while(s<=e){
            int mid= s+(e-s)/2;

            bool value = isvalid(nums, k, mid);
            if(value == true){ //valid h but still find minimised one
                ans=mid;
                e=mid-1;
            }else{ //Matlab capacity bahut chhoti hai. Hume capacity badhani padegi.
                s=mid+1;
            }
        }
        return ans;
    }
};