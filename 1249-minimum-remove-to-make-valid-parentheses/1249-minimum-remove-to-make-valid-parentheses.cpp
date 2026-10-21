class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n= s.size();
        int i=0;
        string ans="";
        int open_count=0;

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
    
        return final;
    }
};