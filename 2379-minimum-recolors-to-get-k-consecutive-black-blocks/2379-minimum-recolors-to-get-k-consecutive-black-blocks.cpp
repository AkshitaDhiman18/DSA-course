#include <climits>
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        //sliding window question as we need to find k consecutive integers

        int n= blocks.size();
        int l=0;
        int count=0;
        int operations = INT_MAX;
        for(int r=0; r<n; r++){
            if(blocks[r] == 'W'){
                count++;
            }

            if((r-l+1) > k){
                if(blocks[l] == 'W') count--;

                l++;
            }

            if((r-l+1) == k){
                operations= min(operations, count);
            }
        }
        return operations; 
    }
};