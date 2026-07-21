#include <algorithm>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> ans;

        int l=0;
        int r=n-1;
        int val1;
        int val2;

        while(l<=r){
            val1= nums[l]*nums[l];
            val2= nums[r]*nums[r];

            if(val1>val2){
                ans.push_back(val1);
                l++;
            }else if(val2>=val1){
                ans.push_back(val2);
                r--;
            }
        }

        

        reverse(ans.begin(), ans.end());
        return ans;
    }
};