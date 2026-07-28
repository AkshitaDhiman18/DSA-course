class Solution {
public:
        //approach1: bruteforce approach
        /*int ans=0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum+=nums[j];
                if(sum == goal){
                    ans++;
                }
            }
        }
        return ans;
    }
};*/
        //approach 2: sliding window
            
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int l = 0, sum = 0, ans = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};


        /*unordered_map<int, int> mp;
        mp[0]=1;
        int prefix=0;
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            prefix+=nums[i];

            if(mp.count(prefix-goal)){
                ans+=mp[prefix-goal];
            }
            mp[prefix]++;
        }
        return ans;
    }
};*/