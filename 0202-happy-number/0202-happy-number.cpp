class Solution {
public:

     int sumofsquareofdigits(int x){
            int sum=0;
            while(x != 0){
                int last= x%10;
                int square= last*last;
                sum+=square;
                x= x/10;
            }
            return sum;
        }

    bool isHappy(int n) {
        //Approach 1: Using visited set(extra space to store every sum for cycle detection)
        /*unordered_set<int> visited;
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
        return true;*/

        //approach 2: cycle detection
        int slow= n;
        int fast=n;

        do{
            slow= sumofsquareofdigits(slow);
            fast= sumofsquareofdigits(sumofsquareofdigits(fast));
        } while(slow != fast);

        if(slow == fast && slow == 1){
            return true;
        }
            return false;
    }
};


        