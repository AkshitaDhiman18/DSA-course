class Solution {
public:

    int count(int a, int b, int mid){
        int r=1;
        int c=b;
        int count=0;
        while(r<=a && c>=1){
            int val = r*c;

            if(val > mid){
                c--;
            }else if(val <= mid){
               count+=c;

               r++;
            }
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
        int low, high;
        low= 1*1;
        high= m*n;

        while(low < high){
            int mid= low+(high-low)/2;

            int count_element= count(m,n,mid);

            if(count_element < k){
                low= mid+1;
            }else if(count_element >= k){
                high= mid;
            }
        }
        return high;
    }
};