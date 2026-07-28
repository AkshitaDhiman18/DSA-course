class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //slidig window+ 2 hashmap
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        vector<int> ans;

       for(int x: p){
        map1[x]++;
       }

       int st=0; 
       int a= p.size();

       for(int end=0; end<s.size(); end++){
        map2[s[end]]++;

        if((end-st+1)>a){
            map2[s[st]]--;

            if(map2[s[st]] == 0){
                map2.erase(s[st]);
            }
            st++;
        }

        
        if(map1 == map2) ans.push_back(st);
        
       }
       return ans;
    }
};