class Solution {
public:
    void do_reverse(vector<char>& s, int l, int r){
        if(l >= r){
            return;
        }

        swap(s[l], s[r]);
        do_reverse(s,l+1,r-1);

    }
    void reverseString(vector<char>& s) {
        //iterative
        /*int n= s.size();
        int l=0;
        int r= n-1;

        while(l<r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return;*/

        //recursive
        int n= s.size();
        int l=0;
        int r= n-1;

        do_reverse(s, l, r);
        return;

    }
};
      