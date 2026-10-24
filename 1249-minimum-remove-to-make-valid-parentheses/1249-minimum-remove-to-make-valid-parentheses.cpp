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
             
            //agr opening bracket mile toh stack mein index dalo uska
            if(ch == '('){
                st.push(r);
            
            //agr closing bracket mile toh
            }else if(ch == ')'){
                //agr stack empty nh h th uska mtlb h ki stack mein opening brcaket hai match kryo aur pop krwa do jise yeh same opening bracket vpis na use hoye
                if(!st.empty()){
                    st.pop();
                //agr empty h stak toh means opening brcaket nh h for current closing bracket so means yhe bracket remove krna h so us index jispe yeh unmatched closing bracket hai vo true krwa do for removal
                }else if(st.empty()){
                    remove[r]= true;
                }
            }
        }
        
        //ab jo bache hue opening bracket h vo uske liye closing bracket nh mila so yeh bhi remove hoyege 
        while(!st.empty()){
            int index= st.top();
            remove[index]= true;
            st.pop();
        }
        //jis index pe false h bs vhi index ki values ko ans mein dalvyo
        string ans="";
        for(int i=0; i<n; i++){
            if(remove[i] == false){
                ans.push_back(s[i]);
            }
        }

        return ans;


    }
};