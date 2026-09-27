class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1= haystack.length();
        int n2= needle.length();

        //edge cases
        if(n1 < n2) return -1;
        if(needle.empty()) return 0;


        int i=0;
        int l=0;
        int r=0;
        int ans=0;

        while(r<n1){
            if(i == n2) return ans;

            if(haystack[r] == needle[i]){
                r++;
                i++;
            }else{
                if(i == n2){
                    return ans;
                }else{
                    i=0;
                    l++;
                    ans=l;
                    r=l;
                }
            }
        }
    if(i == n2) return ans;
    
        return -1;
        
    }
};