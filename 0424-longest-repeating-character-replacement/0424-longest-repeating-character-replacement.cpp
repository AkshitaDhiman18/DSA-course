class Solution {
public:
    int characterReplacement(string s, int k) {

      //Approach 1: Bruteforce approach
      /*int n= s.size();
      unordered_map<char, int> freq;
      int max_freq=0;
      int ans=0;

      for(int start=0; start<n; start++){
        freq.clear();
        for(int end= start; end<n; end++){
            freq[s[end]]++;
            int max_freq=0;
            for(auto it: freq){
                max_freq= max(max_freq, it.second);
            }

            int window_length= end- start+1;

            if(window_length-max_freq <= k){
                ans= max(ans, window_length);
            }
        }
      }
      return ans;*/
      

      //Approach 2: Sliding Window with recalculating max_freq
      int n= s.size();
      int l_ptr=0;
      int max_freq;
      int max_len=0;

      unordered_map<char, int> mp;

      for(int r_ptr=0; r_ptr<n; r_ptr++){
        mp[s[r_ptr]]++;
        max_freq=0;
        for(auto it: mp){
            max_freq= max(max_freq, it.second);
        }

        while((r_ptr-l_ptr+1)-max_freq>k){
            mp[s[l_ptr]]--;
            max_freq=0;
            for(auto it: mp){
                max_freq= max(max_freq, it.second);
            }
            l_ptr++;
        }
        max_len= max(max_len, (r_ptr-l_ptr+1));
      }
      return max_len;
    }
};