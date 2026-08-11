class Solution {
public:

    bool ispossible(vector<int>& time, long long avail_time, int totalTrips){
        int n= time.size();
        long long possible_trips=0;

        for(int i=0; i<n; i++){
            possible_trips+= avail_time/time[i];
        }

        if(possible_trips < totalTrips) return false;

        return true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {

        int n= time.size();
        //bruteforce approch

        //search space
        long long min_time=1; //because time is positive quantity so it cant be in negative and 0 as 0 indicates no time means bus trip kregi hi ni 
        long long max_time = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        /*for(int i= min_time; i<=max_time; i++){
            bool value= ispossible(time, i, totalTrips);

            if(value == true){
                return i;
            }
        }
        return -1;*/

        long long ans=-1;
        long long s=min_time;
        long long e=max_time;

        while(s<=e){
            long long mid= s+(e-s)/2;
            bool value= ispossible(time, mid, totalTrips);

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