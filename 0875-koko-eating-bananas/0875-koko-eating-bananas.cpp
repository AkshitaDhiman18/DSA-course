#include <climits>
#include <cmath>
class Solution {
public:
    
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

        bool isvalid(vector<int>& piles, int mid, int n, int h){
            long long time_required=0;
            for(int i=0; i<n; i++){
                time_required+= ceil((double) piles[i]/mid);
            }

            if(time_required > h){
                return false;
            }
            return true; 
        }
        
        int minEatingSpeed(vector<int>& piles, int h) {
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

            bool value= isvalid(piles, mid, n, h);

            if(value == false){
                s=mid+1;
            }else if(value == true){
                ans = mid;
                e=mid-1;

            }
        }

        return ans;

    }
};