class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        vector<int> res(n,-1);
        
        for(int i=0; i<n; i++){ //current index
            for(int j=1; j<n; j++){ //kitne steps aage jna current element se
                 
                int next_index= (i+j) % n; //for circular nature 
                if(nums[next_index] > nums[i]){
                    res[i]= nums[next_index];
                    break;
                }
            }
        }
        return res;
    }
};