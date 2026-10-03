class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
       
        //frequency count
        for(int i: nums){
            freq[i]++;
        }

        //find maximum
        int maxi=0;
        for(auto it: freq){
            maxi= max(maxi, it.second);
        }

        //add frequency
        int ans=0;
        for(auto it: freq){
            if(maxi== it.second){
                ans+=it.second;
            }
        }
    return ans;
    }
};

