class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int l=0;
        int sum=0;
        int size= INT_MAX;

        for(int r=0; r<n; r++){
            sum+=nums[r];  //expand

            while(sum>=target){
              size= min(size, (r-l+1));

              sum-=nums[l];
              l++;  //shrink
            }
        }
        return(size == INT_MAX) ? 0 : size;
    }
};