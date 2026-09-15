class Solution {
public:
    int missingNumber(vector<int>& nums) {
    /*int a=0;

    for(int i=0; i<=nums.size(); i++){
        a^=i;
    }

    for(int x: nums){
        a^=x;
    }

    return a;*/

    
        unordered_set<int> st;
        for(int i: nums){
            st.insert(i);
        }

        for(int i=0; i<=nums.size(); i++){
            if(!st.count(i)) return i;
        }

        return -1;
    }
};
     