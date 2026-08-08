#include <climits>
class Solution {
public:
    //helper function for both approach
    bool isbloomed(vector<int>& bloomDay, int day, int k, int m){
        int n= bloomDay.size();
        int count = 0;
        int value;
        int total_bouquet_made=0;
        for(int i=0; i<n; i++){
            if(bloomDay[i] <= day){
                count++;
            }else if(bloomDay[i] > day){
                value= count/k;
                if(value > 0) total_bouquet_made+=value;
                count=0;
            }
        }

        value= count/k;
        if(value > 0) total_bouquet_made+=value;

        if(total_bouquet_made >= m){
            return true;
        }else{
            return false;
        }
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        
        long long total_flowers= 1LL* m * k;
        int n= bloomDay.size();

        //imp testcase
        if(total_flowers > n) return -1;

        //search space range
        int min_day= INT_MAX;
        int max_day= INT_MIN;

        for(int a=0; a<n; a++){
            min_day= min(min_day, bloomDay[a]);
            max_day= max(max_day, bloomDay[a]);
        }

        //bruteforce approach
        /*for(int day= min_day; day <= max_day; day++){
            bool bouquet_made= isbloomed(bloomDay, day, k, m);

            if(bouquet_made){
                return day;
            }
        }*/
        //binary search
        int s= min_day;
        int e= max_day;
        int ans=-1;

        while(s<=e){
            int mid= s+(e-s)/2;
            bool value= isbloomed(bloomDay, mid, k, m);

            if(value == true){
                ans= mid;
                e=mid-1;
            }else if(value == false){
                s=mid+1;
            }
        }

        return ans;
        
    }
};