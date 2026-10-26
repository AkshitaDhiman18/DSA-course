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

        for(int i=0; i<n; i++){
            char ch= s[i];

            if(ch == '('){
                open_st.push(i);
            }else if(ch == '*'){
                star_st.push(i);
            }else if(ch == ')'){

                if(!open_st.empty()){
                    open_st.pop();
                }else if(open_st.empty()){
                    if(!star_st.empty()){
                        star_st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }

        while(!open_st.empty() && !star_st.empty()){
            if(open_st.top() < star_st.top()){
                open_st.pop();
                star_st.pop();
            }else{
                return false;
            }
        }

        if(star_st.empty() && !open_st.empty()) return false;
        return true;
        
    }
};