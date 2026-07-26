class Solution {
public:
    int numberOfSubstrings(string s) {
        /*vector<char> characters;
        characters.push_back("a");
        characters.push_back("b");
        characters.push_back("c");*/

        //Bruteforce approach
        /*unordered_map<char, int> mp;
        int n= s.size();
        int ans=0;
        for(int st=0; st<n; st++){
            mp.clear();
            for(int end=st; end<n; end++){
                mp[s[end]]++;

                if(mp.size() >= 3) ans++;  
            }
        }  
        return ans;*/

        //Approach 2:
        int n= s.size();
        int l=0;
        unordered_map<char, int> mp;
        int ans=0;

        for(int r=0; r<n; r++){
            mp[s[r]]++;

            while(mp.size() == 3){
                ans += (n - r);
                
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
        }
        return ans;
    }
};