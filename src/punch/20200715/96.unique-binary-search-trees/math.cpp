#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    long long combinations(int n, int m) {
        if (m > n) {
            return 0;
        }
        long long ret = -1;
        if (m == 0 || m == n) {
            ret = 1;
        } else if (m == 1) {
            ret = n;
        } else {
            ret = combinations(n-1, m-1) + combinations(n-1, m);
        }
        return ret;
    }
    long long arrangements(int n, int m) {
        if (m > n) {
            return 0;
        }
        long long ret = 1;
        for (int i = n; i >= n-m+1; i--) {
            ret *= i;
        }
        return ret;
    }
    int factorial(int n) {
        int ret = 1;
        while (n) {
            ret *= n;
            n--;
        }
        return ret;
    }
};


int main() {
    std::cout << Solution().factorial(19) << std::endl;
}