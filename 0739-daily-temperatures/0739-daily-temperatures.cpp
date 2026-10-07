class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();

        vector<int> answer(n,0);
        stack<int> st;
        st.push(n-1);

        for(int i= n-2; i>=0; i--){
            int curr_temp= temperatures[i];
           

            while(!st.empty() && temperatures[st.top()] <= curr_temp){
                st.pop();
            }

            if(!st.empty()){
                int days_count= st.top() - i;
                answer[i]= days_count;
            }

            st.push(i);
        }
        return answer;  
    }
};