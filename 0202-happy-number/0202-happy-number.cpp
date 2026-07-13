class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> visited;
        visited.insert(n);
        int sum=0;

        while(n!=1){
            while(n!=0){
                int last= n%10;
                int square= last*last;
                sum+=square;
                n= n/10;
            }
            n=sum;
            sum=0;
            if(visited.count(n)){
                return false;
            }else{
                visited.insert(n);  
            }
        }
        return true;
    }
};


        