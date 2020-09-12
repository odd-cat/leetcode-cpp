#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) { return 0; }

        int cashes[2] = {0}, stock = 0;
        cashes[0] = 0;
        stock = -prices[0];
        cashes[1] = std::max(cashes[0], stock + prices[1]);
        stock = std::max(stock, cashes[1] - prices[1]);

        for (auto i = 2; i < prices.size(); ++i) {
            int tmp = cashes[1];
            cashes[1] = std::max(cashes[1], stock + prices[i]);
            stock = std::max(stock, cashes[0] - prices[i]);
            cashes[0] = tmp;
        }
        return std::max(cashes[1], stock);
    }
    int maxProfit2(vector<int>& prices) {
        if (prices.size() <= 1) { return 0; }

        vector<int> stocks(prices.size()), cashes(prices.size());
        cashes[0] = 0;
        stocks[0] = -prices[0];
        cashes[1] = std::max(cashes[0], stocks[0] + prices[1]);
        stocks[1] = std::max(stocks[0], cashes[1] - prices[1]);

        for (auto i = 2; i < prices.size(); ++i) {
            cashes[i] = std::max(cashes[i-1], stocks[i-1] + prices[i]);
            stocks[i] = std::max(stocks[i-1], cashes[i-2] - prices[i]);
        }
        return std::max(cashes[prices.size()-1], stocks[prices.size()-1]);
    }
};

int main() {
    vector<int> prices{1,2,3,0,2};
    std::cout << Solution().maxProfit(prices) << std::endl;
    return 0;
}