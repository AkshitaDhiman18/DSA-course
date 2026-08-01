class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
        int l=0;
        int maximum_fruits=0;
        unordered_map<int, int> basket;

        for(int r=0; r<n; r++){
            basket[fruits[r]]++;

            while(basket.size()>2){
                basket[fruits[l]]--;

                if(basket[fruits[l]] == 0) basket.erase(fruits[l]);

                l++;
            }

            if(basket.size() <= 2){
                maximum_fruits= max(maximum_fruits,(r-l+1));
            }
        }
        return maximum_fruits;
    }
};