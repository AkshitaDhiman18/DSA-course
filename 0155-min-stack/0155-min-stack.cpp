#include <climits>
class MinStack {
public:
    stack<pair<int, int>> st; //value and minvalue 

    MinStack() { 
    }

    void push(int value) {
       if(st.empty()){
        st.push({value, value});  //kyuki agr empty h stack aur ham ush krwa rhe h toh value bhi vhi hogi aur minvalue bhi vahi hoyegi
       }else{
        int minval= min(value, st.top().second);
        st.push({value,  minval});
       }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;  
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */