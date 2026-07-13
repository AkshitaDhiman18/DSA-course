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

        //Approach 2: using extra space (map) but still not an optimal solution as its take extra space
        /*unordered_map<int, int> freq;

        for(int i: nums){
            freq[i]++;
        }

        for(auto it: freq){
            if(it.second > 1){
                return it.first;
            }
        }
        return -1;*/

        //Approach 3: cycle detection using floyd warshall algo
        //begining positions of both the pointers
        int slow=0;
        int fast=0;
        
        //jb tl meeting point h miljata
        do{
            slow= nums[slow];   //as slows moves with 1 step
            fast= nums[nums[fast]];  //and fast moves with 2 steps
        } while(slow != fast);

        //after the end of this loop we will get the meeting point where both the slow and fast pointers stands

        //set any one pointer to the start(i choose fast ptr)
        //now both ptrs moves with step 1
        fast=0;
        while(slow != fast){
        slow= nums[slow];
        fast= nums[fast];
        }
        return fast;
    }
};