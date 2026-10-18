class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n= asteroids.size();
        int i=0;

        stack<int> st;

        while(i<n){

            //agr stack empty nahi hai toh ham check krege ki collision possible hai ya nahi
            if(!st.empty()){  
                int right= asteroids[i];   //current astroid
                int left= st.top();

                //agr collision possible hai toh check krege ki konsa asteriod destroy hoga
                if(left > 0 && right < 0){

                    //jb tk stack empty nahi hota ya fr jb tk stack ka top >0 hoga means left asteroid right jata rhega tb tk collision possible hai (kyuki right vla toh already left jaa rha h yeh ham already uper check kr chuke h ) toh ham tb tk check krege 
                    while(!st.empty() && st.top() > 0){
                        
                        //agr dono ka size same h toh top bhi destroy hoga aur current bhi aur ab current destroy hoga hai toh ab check nh hoga so break ans loop se bhr ajayo
                        if(abs(st.top()) == abs(right)){
                            st.pop();
                            right =0;
                            break;

                        //agr stop chota h aur current bda h toh top ko destroy krdo aur checking continue rkho agle top ke liye
                        }else if(abs(st.top()) < abs(right)){
                                st.pop();
                        //vrna fr agr current chote h toh current ko destroy krke checking rok fdo
                        }else if(abs(st.top()) > abs(right)){
                            right=0;
                            break;
                        }
                    }

                    if(right != 0) st.push(right);

                //agr collision nh hora toh right ko bhi push krta do
                //collision 3 conditions mein nh hoga ya toh dono astroid left ja rhe h, ya fr dono right mein ja rhe h, ya fr left yh left mein jara h aur right vla right mein jisse vo aur door hore h 
                }else{
                    st.push(right);
                }
            
            //agr agar stack hi empty h toh push current
            }else{
                st.push(asteroids[i]);
            }

            i++;
        }

        vector<int> ans;
        if(st.empty()) return ans;

        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};   