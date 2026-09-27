class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int n1= s.size();
        int n2= t.size();

        string ans1;
        string ans2;

        for(int i=0; i<n1; i++){
            if(s[i] == '#'){
                if(!ans1.empty()){
                    ans1.pop_back();
                }
            }else{
                ans1.push_back(s[i]);
            }
        }

        for(int i=0; i<n2; i++){
            if(t[i] == '#'){
                if(!ans2.empty()){
                    ans2.pop_back();
                }
            }else{
                ans2.push_back(t[i]);
            }
        }

        if(ans1 == ans2) return true;

        return false;

    }
};