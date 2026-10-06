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

        for(int i=0; i<n; i++){
            nums.push_back(nums[i]);
        }

        stack<int> st;
        vector<int> res(n);
        st.push(nums[2*n-1]);
        res[(2*n-1) % n]= -1;

        for(int i= 2*n-2; i>=0; i--){
            int curr= nums[i];
            int ans=-1;

            while(!st.empty() && st.top() <= curr){
                st.pop();
            }

            if(!st.empty()) ans= st.top();

            int new_index= i % n;
            res[new_index]= ans;
            st.push(curr);
        }

        return res;


    }
};