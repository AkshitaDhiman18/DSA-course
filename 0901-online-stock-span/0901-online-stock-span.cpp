class StockSpanner {
public:
    vector<int> temp;  //used in bruteforce approach 

    StockSpanner() {  
    }
    
    int next(int price) {

        //bruteforce approach
        
        int n= temp.size();
        int count=1;
    //backward movement
        for(int i=n-1; i>=0; i--){
            if(temp[i] > price){
                break;
            }else if(temp[i] <= price){
                count++;
            }
        }
        //insertion in temp
        temp.push_back(price);

        return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */