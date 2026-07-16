class Solution {
public:
    int maxVowels(string s, int k) {

        int n= s.size();
        int l=0;
        unordered_map<char, int> mp;
        int max_vowel=0;
        int count=0;

        for(int r=0; r<n; r++){
            mp[s[r]]++;

            if((r-l+1) > k){
                mp[s[l]]--;

                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            if((r-l+1) == k){
                for(auto it: mp){
                    if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u'){
                        count+=it.second;
                    }
                }
                max_vowel= max(max_vowel, count);
                count=0;
            }
        }
        return max_vowel; 
    }
};