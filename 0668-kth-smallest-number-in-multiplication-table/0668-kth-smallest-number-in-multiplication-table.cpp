class Solution {
public:
//approach 1: exact approach of ques number 378
    /*int count(int a, int b, int mid){
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
    }*/

//approach 2: Using formula

    int count(int m, int n, int mid){
        int count=0;
        for(int row=1; row<=m; row++){
            count+= min(mid/row, n);
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


