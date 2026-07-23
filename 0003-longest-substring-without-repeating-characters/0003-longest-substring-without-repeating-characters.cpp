class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     //sliding window + hashmap approach
        unordered_map<int, int> mp; 
        int l=0;
        int ans=0;

        for(int h=0; h<s.size(); h++){
            mp[s[h]]++;

            while(mp[s[h]] > 1){  //Jab tak current character duplicate hai tb tak window ko shrink karte rahenge.
                mp[s[l]]--; //Window se bahar ja rahe leftmost character ki frequency decrease kar rahe hain.

                if(mp[s[l]] == 0){  //Check kar rahe hain ki kya woh character window se completely remove ho gaya hai.
                    mp.erase(s[l]);
                }
                l++;  //Duplicate hatane ke liye left pointer ko ek step aage badha kar window shrink karte hain.
            }

            ans= max(ans, h-l+1);
        }
        return ans;
    }
};


//Why do we decrement mp[s[l]] instead of mp[s[h]]?
/*"Because when a duplicate is found, we don't remove the newly added character at h. Instead, we shrink the sliding window from the left. So the character leaving the window is s[l], and only its frequency should be decremented. This keeps the hash map consistent with the current contents of the window."*/  

    