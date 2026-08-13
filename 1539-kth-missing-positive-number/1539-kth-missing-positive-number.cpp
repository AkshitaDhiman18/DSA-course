#include <climits>
class Solution {
public:

   bool ispresent(vector<int>& arr, int a){
    int n= arr.size();
    for(int i=0; i<n; i++){
        if(arr[i] == a) return true;
    }
    return false;
   }
    
   
    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        int max_positive=0;

       
        int count=0;
        //bruteforce approach
        for(int a=1; ; a++){
            bool value= ispresent(arr, a);

            if(value == false) count++;

            if(count == k){
                return a;
            }
        }  
        return -1;

        
    }
};