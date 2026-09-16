class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singlenumber=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            singlenumber^=nums[i];
        }
        return singlenumber;
    }
};