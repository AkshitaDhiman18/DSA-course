class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string ch: tokens){

            if((ch != "+") && (ch != "-") && (ch != "*") && (ch != "/")){
                int element= stoi(ch);
                st.push(element);
            }else{
                int value1= st.top();
                st.pop();
                int value2= st.top();
                st.pop();

                int res;
                if(ch == "+") res= value1 + value2;
                if(ch == "-") res= value2 - value1;
                if(ch == "*") res= value1 * value2;
                if(ch == "/") res= value2 / value1;
                

                st.push(res);
            }
        }
        return st.top();
    }
};