class StockSpanner {
public:
    vector<int> temp;

    StockSpanner() {  
    }
    
    int next(int price) {

        //bruteforce approach
        temp.push_back(price);
        int n= temp.size();
        int count=0;

        for(int i=n-1; i>=0; i--){
            if(temp[i] > price){
                break;
            }else if(temp[i] <= price){
                count++;
            }
        }

        return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */