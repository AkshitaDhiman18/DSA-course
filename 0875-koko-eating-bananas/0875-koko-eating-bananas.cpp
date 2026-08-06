#include <climits>
#include <cmath>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //bruteforce approach

        /*int n= piles.size();
        int max_pile= INT_MIN;

        for(int i=0; i<n; i++){
            max_pile= max(max_pile, piles[i]);
        }

        
        
        for(int x=1; x<=max_pile; x++){
            long long req_hours=0;
            for(int a=0; a<n; a++){
                req_hours+= ceil((double)piles[a]/x);
            }

            if(req_hours <= h) return x;
        }
        return -1;*/
        
        //approach 2:
        int n= piles.size();
        int max_pile= INT_MIN;

        for(int i=0; i<n; i++){
            max_pile= max(max_pile, piles[i]);
        }

        int s=1;
        int e= max_pile;
        int ans=-1;

        while(s<=e){
            int mid= s+(e-s)/2;

            long long time_required=0;
            for(int a=0; a<n; a++){
                time_required+= ceil((double) piles[a]/mid);
            }

            if(time_required > h){
                s=mid+1;
            }else if(time_required <= h){
                ans = mid;
                e=mid-1;

            }
        }

        return ans;

    }
};