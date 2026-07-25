class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n= nums.size();
        int r=0;
        int count=0;
        int maxno=0;

        while(r<n){
            if(nums[r] == 1){
                count+=1;
            }else{
                maxno= max(maxno, count);
                count=0;
            }
            r++;
        }
        maxno= max(maxno, count);
        return maxno;
    }
};