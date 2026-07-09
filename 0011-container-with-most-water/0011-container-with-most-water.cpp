class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0; 
        int r=n-1;
        int marea=0;
        int h;
        int b;
        int a;
        while(l<r){
            h=min(height[l], height[r]);
            b= l-r;

            a=abs(h*b);
            marea=max(marea, a);

            if(height[l] < height[r]){  //agr l ki height ka h toh ky pta aage height jyda milje so l ko increment kro
                l++;
            }else{
                r--; //otherwise r ko incremenet kro
            }
            
        }
        return marea;
    }
};