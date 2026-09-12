class Solution {
public:
    bool check(vector<int>& nums) {
       int n= nums.size();
       int count=0;
       int i;

       for(i=0; i<n-1;i++){
          if(nums[i] > nums[i+1]) count++;
       }

       if(nums[i] > nums[0]) count++;

       if(count == 1 || count == 0) return true;
       return false;
        
       
    }
};