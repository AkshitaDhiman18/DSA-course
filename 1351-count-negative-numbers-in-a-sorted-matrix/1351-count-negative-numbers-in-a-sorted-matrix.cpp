class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       //Approach 1: Binary search
       // rows traverse krte hue sare columns pr binary search lgya hai
       int r= grid.size();
       int c= grid[0].size();
       int f_count=0;

       for(int i=0; i<r; i++){
        int s=0;
        int e=c-1; 
        int count=0;

        while(s<=e){
            int mid= s+(e-s)/2;

            if(grid[i][mid] < 0){
                count= c-mid;
                e=mid-1;
            }else if(grid[i][mid] >=0){
                s=mid+1;
            }
        }
        f_count+=count;
       }
       return f_count;
    }
};