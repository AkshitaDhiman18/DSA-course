class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int sum=0;
        int maxsum=INT_MIN;


        for(int r=0; r<n; r++){
            sum+=nums[r];

            if((r-l+1) > k){
                sum-=nums[l];
                l++;
            }

            if((r-l+1) == k){
                maxsum= max(maxsum, sum);
            }
        }
        return double(maxsum)/k;
    }
};