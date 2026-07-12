class Solution {
public:
    bool isHappy(int n) {
        //Approach 1: Using visited set
        unordered_set<int> visited;
        int sum=0;
        visited.insert(n);

        while(sum!=1 || n!=0){
            if(n!=0){
                int last= n%10;
                int square= last*last;
                sum+=square;
                n=n/10;
            }else{
                n=sum;
                if(visited.count(n)){
                    return false;
                }else{
                    visited.insert(n);
                    sum=0;
                }
            }
        }
        return true;
    }
};