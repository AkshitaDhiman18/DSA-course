class Solution {
public:

    bool ispossibletoreach(vector<int>& dist, int speed, int n, double hour){
        int timetaken=0;
        int a;
        for(a=0; a<n-1; a++){
            timetaken+= ceil((double) dist[a]/ speed);
        }
        double timetaken1;
        if(a == n-1){
            timetaken1= (double)dist[a]/speed;
        }

        if(timetaken + timetaken1 > hour) return false;
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        //bruteforce approach

        int n= dist.size();

        /*for(int speed=1; speed<=1e7; speed++){
            bool value= ispossibletoreach(dist, speed, n, hour);

            if(value == true) return speed;
        }*/

        int s=1;
        int e= 1e7;
        int ans=-1;

        while(s<=e){
            int mid= s+(e-s)/2; //speed

            bool value= ispossibletoreach(dist, mid, n, hour);

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