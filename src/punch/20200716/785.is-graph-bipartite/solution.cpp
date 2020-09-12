#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> nodes(graph.size(), 0);
        for (auto i = 0; i < graph.size(); i++) {
            if (nodes[i] != 0) {
                continue;
            }
            stack<pair<int, int>> stk;
            stk.push(make_pair(i, 1));
            while(!stk.empty()) {
                pair<int, int> nd = stk.top();
                stk.pop();

                if (nodes[nd.first] == 0) {
                    nodes[nd.first] = nd.second;
                    for (auto &n: graph[nd.first]) {
                        stk.push(make_pair(n, -nd.second));
                    }
                } else if (nodes[nd.first] == -nd.second) {
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {
    vector<vector<int>> graph{
        {1,2,3},
        {0,2},
        {0,1,3},
        {0,2}
    };

    std::cout << Solution().isBipartite(graph) << std::endl;

    vector<vector<int>> graph1{
        {1,3},
        {0,2},
        {1,3},
        {0,2}
    };
    std::cout << Solution().isBipartite(graph1) << std::endl;
    return 0;
}