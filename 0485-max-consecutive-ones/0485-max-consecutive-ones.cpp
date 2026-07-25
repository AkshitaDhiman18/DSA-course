class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //Approach 1: this is good optimal approach of traversing an array while maintaining the count of consecutive ones 
        //tc= O(n) and constant space complexity
        /*int n= nums.size();
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
        return maxno;*/

        //Approach 2: sliding window because we need to find the valid window that contains maximum number od consecutive ones
        int n= nums.size();
        int r;
        int maxno=0;
        int l=0;

        for(r=0; r<n; r++){
            if(!(nums[r]==1)){
                maxno= max(maxno, (r-l));
                l=r+1;
            }
        }
        maxno= max(maxno, (r-l));
        return maxno;
    }
};




