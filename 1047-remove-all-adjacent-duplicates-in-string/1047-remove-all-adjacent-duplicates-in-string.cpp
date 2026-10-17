class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int i=0;
        st.push(s[i]);
        i++;

        int n= s.size();

        while(i<n){
            char ch= s[i];
        if(!st.empty()){
            if(st.top() == ch){
                st.pop();
            }else if(st.top() != ch){
                st.push(ch);
            }
        }else{
            st.push(ch);
        }

            i++;
        }

        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;  
    }
};