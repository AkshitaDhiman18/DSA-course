class Solution {
public:
    /*double findpower(double x, int n, long long temp, double power){
        if(temp == 0){
            if(n < 0){
                power= 1/power;
            }
            return power;
        }

        power*=x;

        return findpower(x,n,temp-1,power); //tail recusrion hora hai
        //Function apna khud ka koi calculation return value ke baad mein nahi karta
        //Wo bas recursive call ka result as-it-is aage pass kar deta hai
        //Isliye value bina kisi modification ke seedha top se bottom tak chali jaati hai

    }*/

    double findpower(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }

        double half = findpower(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return findpower(x, N);
    }
};
    /*double myPow(double x, int n) {
        //iterative approach
        /*double power = 1;
        long long temp = abs((long long)n);

        while(temp > 0){
            power*=x;
            temp--;
        }

        if(n < 0){
            power= 1/power;
        }

        return power;

        //recursive approach
        double power = 1;
        long long temp = abs((long long)n);

        double ans= findpower(x,n,temp,power);
        return ans;

    }
};*/