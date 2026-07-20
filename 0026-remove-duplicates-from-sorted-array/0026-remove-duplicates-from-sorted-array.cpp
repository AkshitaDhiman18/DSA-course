class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //approach 1: Brute force approach

        set<int> st;

        for(int i:nums){
            st.insert(i);
        }

        int idx=0;
        for(auto it: st){
            nums[idx]= it;
            idx++;

        }
        return idx;
    }
};
        /*int n=nums.size();

        if(nums.empty()) return 0;
        int l=0;  //l last unique element ka index represent karta hai.
       

        for(int r=1; r<n; r++){  //Pehla element already consider kar liya.
                                  //Ab uske baad wale elements check karne hain.
            if(nums[l] != nums[r]){
                l++;
                nums[l]=nums[r];   //value yha overwrite hori hai
            }
        }
        return l+1;
    }
}; */


//r (Read Pointer): Har element ko exactly ek baar read karta hai aur decide karta hai ki ye unique hai ya duplicate.
//l (Write Pointer): Hamesha last valid unique element ki position maintain karta hai. Jab naya unique milta hai, to usko next valid position par overwrite karke compact array banata hai.