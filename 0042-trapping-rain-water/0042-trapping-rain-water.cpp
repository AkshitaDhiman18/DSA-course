class Solution {
public:
    int trap(vector<int>& height) {
        //Approch 1: Brute Force 
        /*int n=height.size();
        int total_water=0;

        for(int i=0; i<n; i++){
            int leftmax=0;
            int rightmax=0;

            //leftmax
            if(i==0){
                leftmax=height[i];
            }else{
                for(int j=0; j<=i; j++){
                    leftmax=max(leftmax, height[j]);
                }
            }

            //rightmax
            if(i==n-1){
                rightmax= height[i];
            }else{
                for(int k=i; k<n; k++){
                    rightmax=max(rightmax, height[k]);
                }
            }
        int water_level= min(leftmax, rightmax);
        int waterstored= water_level-height[i];

        if(waterstored>=0){
            total_water+=waterstored;
        }
        }
        return total_water;*/


        //Approach 2: Better Brute Force Approach
        //-->first step is to alreadyy find the max element of this array
        /*int n=height.size();
        int max_e=0;
        int max_idx;
        for(int i=0; i<n; i++){
            if(height[i]>max_e){
                max_e=height[i];
                max_idx=i;
            }
        }
        int total_water=0;
        for(int a=0; a<n; a++){
            int right_max=0;
            int left_max=0;
            if(a<=max_idx){
                right_max=max_e;

                for(int b=0; b<=a; b++){
                    left_max=max(left_max, height[b]);
                }
            }

            if(a>=max_idx){
                left_max= max_e;

                for(int c=a; c<n; c++){
                    right_max= max(right_max, height[c]);
                }
            }

            int water_level= min(left_max, right_max);
            int waterstored= water_level-height[a];

            if(waterstored>=0){
                total_water+=waterstored;
            }
        }
        return total_water;*/

        //Approach 3: Better in terms of time complexity
        vector<int> left;
        int n=height.size();
        vector<int> right(n,0);

        //for left vector
        for(int i=0; i<n; i++){
            if(i==0){
                left.push_back(height[i]);
            }else{
                left.push_back(max(height[i], left[i-1]));
            }
        }

        //for right vector
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                right[i]=height[i];
            }else{
                right[i]= max(height[i], right[i+1]);
            }
        }
        int total_water=0;
        for(int i=0; i<n; i++){
            int water_level= min(left[i], right[i]);
            int water_stored= water_level-height[i];

            if(water_stored>=0){
                total_water+=water_stored;
            }
        }
        return total_water;
    }
};