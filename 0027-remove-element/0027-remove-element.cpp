class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //l ----> next correct position
        //r -----> traverse the array
        int n=nums.size();
        int l=0;
        for(int r=0; r<n; r++){
            //if(nums[l] != val){ //here this checks for val...agr val ni milta toh l ko aage badhao aur agr val miljata h toh r check krke swap kryao
               // l++;
            if(nums[r] != val){
                swap(nums[l], nums[r]);
                l++;
            }
        }
        return l;
    }
};

