class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //2 pass approach
        /*int n= s.size();
        int i=0;
        string ans="";
        int open_count=0;

        //1st pass
        while(i<n){
            char ch= s[i];

            if(ch >= 'a' && ch <= 'z'){
                ans.push_back(ch);
            }else if(ch == '('){
                ans.push_back(ch);
                open_count++;
            }else if(ch == ')'){
                if(open_count > 0){
                    ans.push_back(ch);
                    open_count --;
                }
            }
            i++;
        }
        
        string final= "";
        int j=ans.size()-1;
        
        //2nd pass
        while(j >= 0){
            
            char ch= ans[j];

            if(ch >= 'a' && ch <= 'z' || ch == ')'){
                final.push_back(ch);
            }else if(ch == '('){
                if(open_count > 0){
                    open_count--;
                }else if(open_count == 0){
                    final.push_back(ch);
                }
            }

            j--;
        }

        reverse(final.begin(), final.end());
    
        return final;*/

        //stack approach
        int n= s.size();
        stack<int> st;
        vector<bool>remove(n,false);

        for(int r=0; r<n; r++){
            char ch= s[r];

            if(ch == '('){
                st.push(r);

            }else if(ch == ')'){
                if(!st.empty()){
                    st.pop();
                }else if(st.empty()){
                    remove[r]= true;
                }
            }
        }

        while(!st.empty()){
            int index= st.top();
            remove[index]= true;
            st.pop();
        }

        string ans="";
        for(int i=0; i<n; i++){
            if(remove[i] == false){
                ans+=s[i];
            }
        }

        return ans;


    }
};