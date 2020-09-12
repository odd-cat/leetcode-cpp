#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) { return false; }
        int N = matrix.size(), M = matrix[0].size();

        int cur_i = 0, cur_j = M - 1;

        while (cur_i >= 0 && cur_i < N && cur_j >= 0 && cur_j < M) {
            if (target == matrix[cur_i][cur_j]) {
                return true;
            }
            if (target < matrix[cur_i][cur_j]) {
                cur_j--;
            } else {
                cur_i++;
            }
        }
        return false;
    }
};


int main() {
    vector<vector<int>> matrix{
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    std::cout << Solution().findNumberIn2DArray(matrix, 5) << std::endl;
    std::cout << Solution().findNumberIn2DArray(matrix, 20) << std::endl; 
    return 0;
}