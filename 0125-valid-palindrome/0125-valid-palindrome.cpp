#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        int n= s.size();

        int j=0;
        int i=0;

        while(i<n){
            if(isalnum(s[i])){
                s[j]= tolower(s[i]);
                j++;
            }
            i++;
        }

        s.resize(j);  //👉 Ek line mein yaad rakho:
                      //Loop ke andar: j = next free index jahan next valid character store hoga.
                      //Loop ke baad: j = total valid characters (new string ki size).

                      //v.resize(newsize)  or v.resize(newsize, element)

        int a=0;
        int b= s.size()-1;

        while(a<=b){
            if(s[a] != s[b]) return false;

            a++;
            b--;
        }
        return true;
    }
};
