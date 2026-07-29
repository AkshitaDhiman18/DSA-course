class Solution {
public:

    int almost(vector<int> &nums, int a){
      int n= nums.size();
      int l=0;
      int ans=0;
      unordered_map<int, int> f;

      for(int r=0; r<n; r++){
        f[nums[r]]++;

        while(f.size()> a){
            f[nums[l]]--;

            if(f[nums[l]] == 0) f.erase(nums[l]);
            l++;
        }

        ans+=(r-l+1);
      }

      return ans;    

    }



    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return almost(nums, k)-almost(nums, k-1);
    }
};