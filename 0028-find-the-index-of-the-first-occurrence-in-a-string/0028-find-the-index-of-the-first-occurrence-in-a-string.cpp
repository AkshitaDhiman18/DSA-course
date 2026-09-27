class Solution {
public:

    int first_occ(string haystack, string needle, int i, int l, int r, int ans, int n1, int n2){

        if(r == n1){
            if(i == n2) return ans;
            return -1;
        }

        if(i == n2) return ans;
        if(haystack[r] == needle[i]){
            r++;
            i++;
        }else{
            i=0;
            l++;
            ans=l;
            r=l;
        }

        return first_occ(haystack, needle,i, l, r, ans, n1, n2);

    }

    int strStr(string haystack, string needle) {

    //BRUTEFORCE APPROACH
        int n1= haystack.length();
        int n2= needle.length();

        //edge cases
        if(n1 < n2) return -1;
        if(needle.empty()) return 0;


        int i=0;
        int l=0;
        int r=0;
        int ans=0;

        /*while(r<n1){
            if(i == n2) return ans;

            if(haystack[r] == needle[i]){
                r++;
                i++;
            }else{
                i=0;
                l++;
                ans=l;
                r=l;
                }
        }
    if(i == n2) return ans;

        return -1;*/
    
    //RECURSIVE APPROACH

    return first_occ(haystack, needle, i, l, r, ans, n1, n2);
        
    }
};