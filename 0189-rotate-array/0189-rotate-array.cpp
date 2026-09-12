class Solution { 
public: 
    void rotate(vector<int>& nums, int k) { 
        int n=nums.size(); 
        if(n==1) return; 
        if(k==0) return; 
        vector<int> temp; 
        
             
        k= k%n; 
             
        for(int i=n-k; i<n; i++){ 
            temp.push_back(nums[i]); 
        } 
        for(int j= n-k-1; j>=0; j--){ 
            nums[j+k]= nums[j]; 
        } 
 
        for(int x=0; x<temp.size(); x++){ 
            nums[x]= temp[x]; 
        } 
        return; 
    } 
};  