#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        if (n == 0) { return 0; }
        vector<int> g(n+1, 0);
        g[0] = 1;
        g[1] = 1;

        for (int i = 2; i <= n; i++) {
            int mid = int(i/2);
            for (int j = 0; j < mid; j++) {
                g[i] += 2 * g[j] * g[i-j-1];
            }
            if (i % 2 == 1) {
                g[i] += g[mid] * g[mid];
            }
        }
        return g[n];
    }
};


int main() {
    std::cout << Solution().numTrees(19) << std::endl;
}