class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r= matrix.size();
        int c= matrix[0].size();
        int n= r*c;
        int s=0;
        int e= n-1;
        int mid;

        while(s<=e){
            mid=s+(e-s)/2;

            int ri= mid/c;
            int ci= mid%c;

            if(matrix[ri][ci] == target) return true;
            if(matrix[ri][ci] < target) s=mid+1;
            if(matrix[ri][ci] > target) e=mid-1;
        }
        return false;
    }
};