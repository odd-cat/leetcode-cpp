#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


class Trie {
    struct Node {
        Node *branches[26] = {NULL};
        bool tail;
        Node(): tail(false) {}
    };
public:
    Trie(vector<string> &dictionary) {
        for (auto &s: dictionary) {
            this->insert(s);
        }
    }
public:
    bool search(const string &str) {
        Node *cur = &root;
        auto i = 0;
        while (cur && i < str.size()) {
            //std::cout << *it << " ";
            int loc = str[i] - 'a';
            cur = cur->branches[loc];
            i++;
        }
        //std::cout << std::endl;
        return cur != NULL && cur->tail;
    }
    bool search(string::iterator begin, string::iterator end) {
        Node *cur = &root;
        auto it = begin;
        while (cur && it <= end) {
            //std::cout << *it << " ";
            int loc = *it - 'a';
            cur = cur->branches[loc];
            it++;
        }
        //std::cout << std::endl;
        return cur != NULL && cur->tail;
    }

    void insert(const string &str) {
        Node *cur = &root;
        for (auto &ch: str) {
            int loc = ch - 'a';
            if (cur->branches[loc] == NULL) {
                cur->branches[loc] = new Node;
            }
            cur = cur->branches[loc];
        }
        cur->tail = true;
     }
private:
    Node root;
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        Trie trie(dictionary);

        vector<int> dp(sentence.size() + 1);
        for (auto i = 1; i <= sentence.size(); ++i) {
            dp[i] = dp[i-1] + 1;
            for (auto j = 0; j < i; ++j) {
                //if (trie.search(sentence.substr(j, i - j))) {
                //    std::cout << sentence.substr(j, i - j) << std::endl;
                //    dp[i] = std::min(dp[i], dp[j]);
                //}
                if (trie.search(sentence.begin() + j, sentence.begin() + i-1)) {
                    dp[i] = std::min(dp[i], dp[j]);
                }
            }
        }
        return dp[sentence.size()];
    }
    int respace2(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict;

        std::copy(dictionary.begin(), dictionary.end(), std::inserter(dict, dict.end()));
        vector<int> dp(sentence.size() + 1);
        for (auto i = 1; i <= sentence.size(); ++i) {
            dp[i] = dp[i-1] + 1;
            for (auto j = 0; j < i; ++j) {
                if (dict.find(sentence.substr(j, i - j)) != dict.end() ) {
                    dp[i] = std::min(dp[i], dp[j]);
                }
            }
        }
        return dp[sentence.size()];
    }
};


int main() {
    vector<string> dictionary{"looked","just","like","her","brother"};
    std::cout << Solution().respace(dictionary, "jesslookedjustliketimherbrother") << std::endl;

    Trie trie(dictionary);
    string str = "jesslookedjustliketimherbrother";
    std::cout << trie.search(str.begin(), str.begin()+4) << std::endl;
    std::cout << trie.search(str.begin()+4, str.begin()+10) << std::endl;
    std::cout << trie.search(str.begin()+10, str.begin()+14) << std::endl;
    return 0;
}