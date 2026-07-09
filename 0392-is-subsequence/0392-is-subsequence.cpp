class Solution {
public:
    bool isSubsequence(string s, string t) {
    if(s.empty()) return true;

    int i=0; //points to string s(jo character string s ka search krna hai)
    for(int j=0; j<t.size(); j++){ //j for string t (jis string mein search krna hai)
        if(t[j]==s[i]){
            i++;
        }

        if(i==s.size()){
            return true;
        }
    }
    return false;
    }
};
