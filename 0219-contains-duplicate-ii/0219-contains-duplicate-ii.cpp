class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       int n= nums.size();

       /*for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j && nums[i] == nums[j] && abs(i-j) <=k){
                return true;
            }
        }
       }
       return false;*/

       unordered_map<int, int> track;

       for(int i=0; i<n; i++){
        if(track.count(nums[i])){
            int val1= i;
            int val2= track[nums[i]];
            if(abs(val1 - val2) <=k){
                return true;
            }else{
                track[nums[i]]=i;
            }
        }else{
            track[nums[i]]=i;
        }
       }
       return false;
    }
};