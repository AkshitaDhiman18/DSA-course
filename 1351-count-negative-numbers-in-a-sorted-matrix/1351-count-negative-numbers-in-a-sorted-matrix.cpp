class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       //Approach 1: Binary search
       // rows traverse krte hue sare columns pr binary search lgya hai
       /*int r= grid.size();
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
       return f_count;*/

       //Approach 2: Traversal from top right
       //top right se start kro
       //agr -1 miljata h toh us column ke sare bache hue elements bhi 0 se less than hoge kyuki columns bhi sorted h toh sare elements ek sth add kra ke column ko decremenet krdo
       int r= grid.size();
       int c= grid[0].size();
       int f_count=0;

       int i=0;
       int j=c-1;

       while(i<r && j>=0){
        int count=0;
        if(grid[i][j] < 0){
            count= r-i;
            j--;
        }else if(grid[i][j] >= 0){
            i++;
        }
        f_count+=count;
       }
       return f_count;
    }
};