#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }
        int N = triangle.size();
        vector<int> dp(N+1);
        for (int i = N - 1; i >= 0; i--) {
            for (auto j = 0; j <= i; j++) {
                //std::cout << i << " " << j << std::endl;
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};

int main() {
    vector<vector<int>> triangle{
           {2},
          {3,4},
         {6,5,7},
        {4,1,8,3}
    };
    std::cout << Solution().minimumTotal(triangle) << std::endl;
    return 0;
}