class Solution {
public:
    int search(vector<int>& nums, int target){
        int n=nums.size();
        int s=0;
        int e=n-1;

        while(s<=e){
            int mid= s+(e-s)/2;  //find mid
            
            if(nums[mid]==target){
                return mid;
            }

            //sorted array check
            if(nums[s]<=nums[mid]){ //left sorted half(se mtlb hota h mid se phela half left)

                //binary search on left sorted half
                if(target>=nums[s] && target<nums[mid]){
                    e=mid-1;  //Agar target left sorted part mein hai → right part ko hata do (e = mid - 1).
                              //Agar target left sorted part mein nahi hai → left part ko hata do (s = mid + 1).
                }else{
                    s=mid+1; //means target left part mein nh hai array sorted hone ke bd bhi toh ham right move krege(s=mid+1)
                }
            }else if(nums[s] > nums[mid]){ //right sorted half(se mtlb h mid se bdd vla half right)

                //binary search on right sorted half
                if(target>nums[mid] && target<=nums[e]){
                    s=mid+1;  //target right mein  hai toh left part hata do
                }else{
                    e=mid-1;  //right mein nh hai toh right hata do left side check kro
                }
            }
            }
            return -1;
    }
};

            