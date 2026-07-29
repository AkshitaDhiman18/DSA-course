class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //Bruteforce approach
        /*int n= cardPoints.size();
        int sum;
        int a=0;
        int maxscore=0;
        while(a<=k){
            sum=0;
            if(a!=0){
                for(int i=0; i<a; i++){
                    sum+=cardPoints[i];
                }
            }

            if(a!=k){
                for(int j=n-1; j>=n-k+a; j--){
                    sum+=cardPoints[j];
                }
            }

            maxscore= max(maxscore, sum);
            a++;
        }
        return maxscore;*/

        int n= cardPoints.size();
        int lsum=0;
        int rsum=0;

        for(int i=0; i<k; i++){
            lsum+=cardPoints[i];
        }

        int maxscore= max(lsum, rsum);
        int l=k-1;
        int r=n-1;
        while(l>=0){
            lsum-=cardPoints[l];
            l--;
            rsum+=cardPoints[r];
            r--;

            maxscore= max(maxscore, lsum+rsum);
        }
        return maxscore; 
    }
};