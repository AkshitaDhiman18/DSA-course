class Solution {
public:

    bool isvowel(char x){
        return x=='a' || x=='e' || x=='i' || x=='o' || x=='u';
    }

    int maxVowels(string s, int k) {
        int n=s.size();
        int l=0;
        int count=0;
        int max_vowel=0;

        for(int r=0; r<n; r++){
            
            if(isvowel(s[r])){
                count++;
            }

            if((r-l+1) > k){
                if(isvowel(s[l])){
                    count--;
                }
                l++;
            }

            if((r-l+1) == k){
                max_vowel= max(count, max_vowel);
            }
        }
        return max_vowel;
    }
};

       