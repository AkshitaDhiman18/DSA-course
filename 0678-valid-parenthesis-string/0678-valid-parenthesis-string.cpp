class Solution {
public:
    //in recursion approach:-
    /*bool isvalidstring(int i, int open, int len, string &s){
        //base case
        if(open < 0) return false; //agr open minus mein hai toh invalid string hogi kyuki ab koi bhi closing bracket ke liye open nh mila
        if(i == len){ //agr puri string tranverse krli hai
            if(open == 0) return true; //aur open 0 hai means sare open bracket valid trilke se close hoge hai
            if(open > 0) return false; //agr open >0 hai means koi valid closing ni mili opening bracket ko
        }

        char ch= s[i];
        
        //agr open bracket mila toh open counter++ kro aur agle index pe check kro
        if(ch == '('){ 
            return isvalidstring(i+1, open+1, len, s);
        }
        
        //agr closing bracket mila toh open counter-- kro kyuki ek open bracket valid close ho chuka hain aur next index check kro
        if(ch == ')'){
            return isvalidstring(i+1, open-1, len, s);
        }

        //agr * aya h toh tino choose explore krooo jisse bhi true aya means tring is valid aur vo choose shi hai isliye || use kra hai
        return(isvalidstring(i+1, open+1, len, s) || isvalidstring(i+1, open-1, len, s) || isvalidstring(i+1, open, len, s));
    }*/

    bool checkValidString(string s) {
        //bruteforce approach:- recursion

        /*int open=0;
        int n= s.size();
        int i=0;

        bool ans= isvalidstring(i,open,n,s);
        return ans;*/

        // approach 1:- 2 stack approach
        stack<int> open_st;
        stack<int> star_st;
        int n= s.size();
        
        //phase 1:
        for(int i=0; i<n; i++){
            char ch= s[i];

            if(ch == '('){  //push index into stack
                open_st.push(i);
            }else if(ch == '*'){ //push index into stack
                star_st.push(i);
            }else if(ch == ')'){  //check for match

                if(!open_st.empty()){  //agr open_st empty nh hua mtlb opening bracket h match hogya now open bracket ko pop krdo
                    open_st.pop();
                }else if(open_st.empty()){ //agr empty hai toh 
                    if(!star_st.empty()){  //dusra option check krege agr star empty nh h toh means * mila isko open bracket smj ke pop krdo
                        star_st.pop();
                    }else{
                        return false;  //agr star bhi empty hogya mena kch bhi nh h close ko match krne ke liye toh invalid string return false
                    }
                }
            }
        }

        //phase 2: 
        //jb tk dono stack empty nh hote h check kro ki ky * open bracket ke bd hai? 
        while(!open_st.empty() && !star_st.empty()){
            //agr hn bd mein hai toh dono ko pop krdo kyuki dono match hoge hai as hmne * ko ) mana hai 
            if(open_st.top() < star_st.top()){
                open_st.pop();
                star_st.pop();
                //agr star phele h toh menas invalid h paranthesis return false
            }else{
                return false;
            }
        }
        
        //agr still open bracket bach gye h aur star khtm hoge means open bracket ko match krne ke liye kch nh bcha return false
        if(star_st.empty() && !open_st.empty()) return false;
        //aur agr star bachgye h toh unhe empty string smj lo return true
        return true;
        
    }
};