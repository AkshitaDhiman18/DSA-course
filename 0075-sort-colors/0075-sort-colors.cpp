class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        int low=0;
        int high=n-1;
        int mid= 0;


        while(mid<=high){
            if(nums[mid] == 0){
                if(low != mid){
                swap(nums[mid], nums[low]);
                low++;
                }else{
                    mid++;
                    low++;
                }
            }else if(nums[mid]==2){
                if(nums[high] !=2){
                swap(nums[mid], nums[high]);
                high--;
                }else{
                    high--;
                }
            }else if(nums[mid]==1){
                mid++;
            }
        }
        return;
    }
};