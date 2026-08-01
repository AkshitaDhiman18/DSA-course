#include <climits>
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        //sliding window question as we need to find k consecutive integers

        int n= blocks.size();
        int l=0;
        int recolor=0;
        int operations = INT_MAX;
        for(int r=0; r<n; r++){
            if(blocks[r] == 'W'){
                recolor++;
            }

            if((r-l+1) > k){
                if(blocks[l] == 'W') recolor--;

                l++;
            }

            if((r-l+1) == k){
                operations= min(operations, recolor);
            }
        }
        return operations; 
    }
};