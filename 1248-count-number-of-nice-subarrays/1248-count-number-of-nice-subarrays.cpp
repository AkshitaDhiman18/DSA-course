class Solution {
public:
    
    int almost_count(vector<int> &nums, int goal){
        if(goal < 0) return 0;
        int n= nums.size();
        int l=0;
        int ans=0;
        int count=0;

        for(int r=0; r<n; r++){
            if(nums[r]%2 != 0) count++;

            while(count>goal){
                if(nums[l]%2 != 0) count--;
                l++;
            }
            int length= r-l+1;
            if(count<=goal) ans+= length;
        }
        return ans;
    }


    int numberOfSubarrays(vector<int>& nums, int k){
        return almost_count(nums, k) - almost_count(nums, k-1);
    }
};

        /*unordered_map<int, int> mp;
        mp[0]=1;
        int prefix=0;
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                prefix+=0;
            }else{
                prefix+=1;
            }


            if(mp.count(prefix-k)){
                ans+= mp[prefix-k];
            }

            mp[prefix]++;
        }
        return ans;*/


   