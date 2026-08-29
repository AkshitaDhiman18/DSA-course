class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;

        
        if(target < nums[s]) return s;
        int mid;
        while(s<=e){
            mid= s+(e-s)/2;

            if(nums[mid] == target){
                return mid; //target found return the position
            }
            if(nums[mid] > target){
                e=mid-1;  //mid is greater than target so move left
            }
            if(nums[mid] < target){
                    s=mid+1;   //mid is less tha target so move right
                }
            }
            return s;  //After the loop:
                       //s = first position where the target can be inserted(elment>=target) (lower bound).
                       //e = last position where the value is strictly smaller than the target. 
                       //that why we returned the s
    }
    };
    
