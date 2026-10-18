class Solution {
public:
    string decodeString(string s) {

        stack<string> b_alpha;
        stack<string> nums;
        string ans="";
        int n= s.size();
        int i=0;
        

        while(i<n){
            char ch= s[i];

            if(ch >= '0' && ch <= '9'){
                string nums_s= "";

                while(s[i] >= '0' && s[i] <= '9'){
                    nums_s.push_back(s[i]);
                    i++;
                }

                nums.push(nums_s);

            }else if(ch== '['){
                b_alpha.push(string(1,ch));
                i++;

            }else if(ch >= 'a' && ch <= 'z'){
                string alpha="";

                while(s[i] >= 'a' && s[i] <= 'z'){
                    alpha.push_back(s[i]);
                    i++;
                }

                b_alpha.push(alpha);

            }else if(ch == ']'){
                string part="";

                while(!b_alpha.empty() && b_alpha.top() != "["){
                    part= b_alpha.top() + part;
                    b_alpha.pop();
                }
                b_alpha.pop();

                
    
                int repeat= stoi(nums.top());
                nums.pop();

                string decoded_part="";

                for(int j=1; j<= repeat; j++){
                    decoded_part+=part;
                }
                
                b_alpha.push(decoded_part);
                
                i++;
            } 
        }
        
        stack<string> final_stack;
        while(!b_alpha.empty()){
            if(b_alpha.top() == "["){
                b_alpha.pop();
            }else{
                final_stack.push(b_alpha.top());
                b_alpha.pop();
            }
        }

        while(!final_stack.empty()){
            ans+=final_stack.top();
            final_stack.pop();
        }

        return ans;

    }
}; 