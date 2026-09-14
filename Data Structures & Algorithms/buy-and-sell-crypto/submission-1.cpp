class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=0;
        int val=0;
        int i=0;
        for(i;i<prices.size()-1;i++){
            if(prices[i]<prices[min]){
                min=i;
            }
            val= max(prices[i]-prices[min], val);
        }
        return max(prices[i]-prices[min], val);
    }
};
