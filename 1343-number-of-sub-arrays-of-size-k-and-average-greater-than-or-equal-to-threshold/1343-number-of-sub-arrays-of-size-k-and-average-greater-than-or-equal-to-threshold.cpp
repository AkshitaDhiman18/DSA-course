class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();

        int l=0;
        int sum=0;
        int count=0;

        for(int r=0; r<n; r++){
            sum+=arr[r];

            if((r-l+1) > k){
                sum-=arr[l];
                l++;
            }

            if((r-l+1) == k){
                if(sum >= threshold *k){
                    count++;
                }
            }
        } 
        return count;    
    }
};