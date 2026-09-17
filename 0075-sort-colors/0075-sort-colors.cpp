class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        //bruteforce approach
        /*sort(nums.begin(), nums.end());
        return;*/

        //optimised approach
        int count_ones=0;
        int count_zeros=0;
        int count_twos=0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0) count_zeros++;
            if(nums[i] == 1) count_ones++;
            if(nums[i] == 2) count_twos++;
        }

        int i, j, k;

        for(i=0; i<count_zeros; i++){
            nums[i]= 0;
        }

        for(j=i; j<i+count_ones; j++){
            nums[j]= 1;
        }

        for(k= j; k<j+count_twos; k++){
            nums[k]= 2;
        }

        return;


        //optimal approch
        /*if(n==1) return;
        int low=0;
        int high=n-1;
        int mid= 0;


        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
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
        return;*/
    }
};