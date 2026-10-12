class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //this ques is of finding next smaller element
        int n= prices.size();

        stack<int> st;
        st.push(prices[n-1]);

        for(int i= n-2; i>=0; i--){
            int curr= prices[i];

            while(!st.empty() && st.top() > curr){
                st.pop();
            }

            if(!st.empty()){
                int ans= st.top();
                prices[i]= curr - ans;
            }

            st.push(curr);
        }

        return prices;
    }
};