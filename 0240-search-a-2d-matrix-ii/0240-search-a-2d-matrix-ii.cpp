class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*int r= matrix.size();
        int c= matrix[0].size();
        int n= r*c;
        int ri=0;
        int ci= c-1;

        if(n == 1){
            if(matrix[ri][ci] == target){
                return true;
            }else {
                return false;
            }
        }

        while(ri<r && ci>=0){
            if(matrix[ri][ci] == target) return true;

            if(matrix[ri][ci] > target){
                ci--;
            }else if(matrix[ri][ci] < target){
                ri++;
            }
        }
        return false;*/

        int r= matrix.size();
        int c= matrix[0].size();
        int n= r*c;
        int ri=r-1;
        int ci=0;


        if(n == 1){
            if(matrix[ri][ci] == target){
                return true;
            }else {
                return false;
            }
        }

        while(ri>=0 && ci<c){
            if(matrix[ri][ci] == target) return true;

            if(matrix[ri][ci] > target){
                ri--;
            }else if(matrix[ri][ci] < target){
                ci++;
            }
        }
        return false;
    }
};