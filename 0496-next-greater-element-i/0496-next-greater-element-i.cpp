class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*int n1= nums1.size();
        int n2= nums2.size();
        int temp;
        int ans;

        for(int i=0; i<n1; i++){
            for(int j=0; i<n2; j++){
 
                if(nums1[i] == nums2[j]){
                    temp=j;
                    break;
                }
            }

            for(int a=temp; a<n2; a++){
                ans=-1;

                if(nums1[i] < nums2[a]){
                    ans= nums2[a];
                    break;
                }
            }

            nums1[i]= ans;
        }

        return nums1;*/
        int n= nums2.size();
        stack<int> st;
        unordered_map<int, int> nge;

        st.push(nums2[n-1]);
        nge[nums2[n-1]]=-1;

        for(int i=n-2; i>=0; i--){
            int ans=-1;
            int curr= nums2[i];

            while(!st.empty() && st.top() <= curr){
                st.pop();
            }

            if(!st.empty()) ans= st.top();

            st.push(curr);
            nge[nums2[i]]= ans;
        }
        
        int n1= nums1.size();
        for(int i=0; i<n1; i++){
            nums1[i]= nge[nums1[i]]; 
        }

        return nums1;

    }
};