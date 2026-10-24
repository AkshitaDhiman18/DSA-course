class Solution {
public:
    int minAddToMakeValid(string s) {
    //stack based approach
        int n= s.size();
        if(n==0) return 0;
        int minimum_add=0;

        stack<int> st;

        for(int i=0; i<n; i++){
            char ch= s[i];

            if(ch == '('){
                st.push(ch);
            }else if(ch == ')'){
                if(st.empty()){
                    minimum_add++;
                }else if(st.top() == '('){
                    st.pop();
                }
            }
        }

        int size= st.size();
        minimum_add+= size;

        return minimum_add;
  
    }
};