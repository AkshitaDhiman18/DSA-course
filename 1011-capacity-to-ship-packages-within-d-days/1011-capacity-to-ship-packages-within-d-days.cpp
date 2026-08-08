#include <climits>
class Solution {
public:

    bool ispossible(vector<int>& weights, int capacity, int days){
        int n= weights.size();
        int sum=0;
        int days_required=0;

        for(int i=0; i<n; i++){
            sum+=weights[i];

            if(sum>capacity){
                sum=weights[i];
                days_required++;
            }

            if(sum == capacity){
                days_required++;
                sum=0;
            }
        }

        if(sum > 0) days_required++; //sirf tab day count karo jab kuch weight pending ho:


        if(days_required > days) return false;
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        
        //search space 
        int min_capacity= INT_MIN;
        int max_capacity=0;

        for(int i=0; i<n; i++){
            min_capacity= max(min_capacity, weights[i]);
            max_capacity+=weights[i];
        }
        //bruteforcee approach
        /*for(int capacity= min_capacity; capacity<= max_capacity; capacity++){
            bool value= ispossible(weights, capacity, days);

            if(value == true){
                return capacity;
            }
        }*/
        
        //binary search
        int s= min_capacity;
        int e= max_capacity;
        int ans=-1;
        while(s<=e){
            int mid= s+(e-s)/2;

            bool value= ispossible(weights, mid, days);

            if(value == false){
                s=mid+1;
            }else if(value == true){
                ans= mid;
                e=mid-1;
            }


        }

        return ans;
    }
};