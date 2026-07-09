class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Approach 1: BRUTEFORCE APPROACH
        /*set<vector<int>> st;
        int n=nums.size();
        for(int i=0; i<n-2; i++){ //loop for 1st element of triplet
            for(int j=i+1; j<n-1; j++){ //loop for 2nd element of triplet
                for(int k=j+1; k<n; k++){   //loop for 3rd element of triplet
                    if(nums[i]+nums[j]+nums[k] == 0){  //sum check
                        vector<int> temp = {nums[i], nums[j], nums[k]};  //push in temp
                        sort(temp.begin(), temp.end()); //now sort temp for checkig for duplicate
                        st.insert(temp); //insert in set as set only keeps unique data so we automatically gets unique tripets
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end()); //return in 2d vectors as already mentioned retur type
        return ans;*/


        //Approach 2: HASHING to reduce tc to O(n^2)
        /*set<vector<int>> stt;
        int n=nums.size();
        for(int i=0; i<n-1; i++ ){
            unordered_set<int> st;
            for(int j=i+1; j<n; j++){
              int k= -(nums[i]+nums[j]);
              if(st.count(k)){
                vector<int> temp= {nums[i], nums[j], k};
                sort(temp.begin(), temp.end());
                stt.insert(temp);
              }else{
                st.insert(nums[j]);
              }
            }
        }
        vector<vector<int>> ans(stt.begin(), stt.end()); 
        return ans;*/

        //Approach 3: OPTIMAL APPROACH (two pointers + sorting)
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]== nums[i-1]) continue;

            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum= nums[i] + nums[j] +nums[k];

                if(sum>0){
                    k--;
                }else if(sum<0){
                    j++;
                }else{
                    vector<int> temp= {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};