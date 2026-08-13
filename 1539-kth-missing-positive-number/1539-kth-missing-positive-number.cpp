#include <climits>
class Solution {
public:

   /*bool ispresent(vector<int>& arr, int a){
    int n= arr.size();
    for(int i=0; i<n; i++){
        if(arr[i] == a) return true;
    }
    return false;
   }*/
    
   
    int findKthPositive(vector<int>& arr, int k) {
        /*int n= arr.size();
        int max_positive=0;

       
        int count=0;
        //bruteforce approach
        /*for(int a=1; ; a++){
            bool value= ispresent(arr, a);

            if(value == false) count++;

            if(count == k){
                return a;
            }
        }
         
        return -1;*/
        int n = arr.size();

        int left = 0;
        int right = n;

        while (left < right) {

            int mid = left + (right - left) / 2;

            // Number of missing elements before arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                // Missing numbers abhi kam hain
                // Right side jaana hai
                left = mid + 1;
            }
            else {
                // K missing numbers mil gaye
                // Ho sakta hai answer left side mein ho
                right = mid;
            }
        }

        // left = first index where missing >= k
        return left + k;
    }
};

  