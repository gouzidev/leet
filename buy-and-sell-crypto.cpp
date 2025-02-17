#include "helper.cpp"

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int buyPrice = prices[0];
        int selPrice = prices[0];
        int bestPrice = 0;
        for (int &price : prices)
        {
            if (price < buyPrice)
            {
                buyPrice = price;
                selPrice = price;
            }
            else if (price > selPrice)
                selPrice = price;
            if (selPrice - buyPrice > bestPrice)
                bestPrice = selPrice - buyPrice;
        }
        return bestPrice; 
    }
};


int main() {
    // Create test cases
    Solution solution;
    vector <int> prices = {10,8,7,5,2};
    int res = solution.maxProfit(prices);
    cout << "profit =>  " << res << endl;
    
    return 0;
}
