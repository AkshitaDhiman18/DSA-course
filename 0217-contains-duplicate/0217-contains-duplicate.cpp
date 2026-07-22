class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for(int a: nums){
            map[a]++;
        }
        for(auto it: map){
            if(it.second > 1) return true;
        }
        return false;
        
    }
};

//tc= O(n)
//sc= O(n)