class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //this ques is of finding next smaller element
        int n= prices.size();

        stack<int> st;
        st.push(prices[n-1]);

        for(int i= n-2; i>=0; i--){
            int curr_price= prices[i];

            while(!st.empty() && st.top() > curr_price){
                st.pop();
            }

            if(!st.empty()){
                int discount= st.top();
                prices[i]= curr_price - discount;
            }

            st.push(curr_price);
        }

        return prices;
    }
};