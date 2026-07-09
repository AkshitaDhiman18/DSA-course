class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*int index=-1;
        unordered_map<int, int> idx;

        for(char a: t){
            idx[a]=a;
        }

        for(int i=0; i<s.size(); i++){
            if(idx.count(s[i])){
                if(index > idx[s[i]]){
                    return false;
                }else{
                    index=idx[s[i]];
                }
            }else{
                return false;
            }
        }
        return true;
    }
};*/
    if(s.size() == 0 && t.size() == 0) return true;

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
