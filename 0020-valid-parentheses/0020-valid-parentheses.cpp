class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;  //odd length string is not valid

        stack<char> st;

        for(char ch: s){
            //agr opening bracket mile toh stack mein dalva do
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            //agr closing bracket mile toh check kro:
            }else{
                //agr stack empty h toh mt kuch opening ka h hi nh jisko close kre toh return false
                if(st.empty()) return false;

                char top= st.top();
                st.pop();

                if((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) return false;

            }
        } 

        if(st.empty()) return true;

        return false;
    }
};