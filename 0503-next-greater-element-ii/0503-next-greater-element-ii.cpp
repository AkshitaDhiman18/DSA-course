class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //Bruteforce approach
        /*int n= nums.size();
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
        return res;*/

        //optimal approach

        int n= nums.size();
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            st.push(nums[i]);
        }

        for(int j=n-1; j>=0; j--){
            int ans=-1;
            int curr=nums[j];

            while(!st.empty() && st.top() <= curr){
                st.pop();
            }

            if(!st.empty()) ans= st.top();

            nums[j]= ans;
            st.push(curr);
        }

        return nums;
    }
};