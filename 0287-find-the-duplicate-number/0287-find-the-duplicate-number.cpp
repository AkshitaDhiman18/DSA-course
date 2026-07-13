class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //Approach 1: Solution using sorting but this is not optimal ans because its already mention in the constraints that array should not be modified
        /*sort(nums.begin(), nums.end());
        int n=nums.size();

        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return -1;*/

        //Approach 2: using extra space (map)
        unordered_map<int, int> freq;

        for(int i: nums){
            freq[i]++;
        }

        for(auto it: freq){
            if(it.second > 1){
                return it.first;
            }
        }
        return -1;
    }
};