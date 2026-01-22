/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

struct TrieNode {
    std::map<char, TrieNode*> children;
    int count;

    TrieNode() : count(0) {}
};

void insert(TrieNode* root, const std::string& s) {
    TrieNode* current = root;
    for (char ch : s) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
        current->count++;
    }
}

void findCommonPrefixes(TrieNode* node, int k, std::string currentPrefix, std::vector<std::string>& result) {
    if (node == nullptr) {
        return;
    }

    for (auto const& [key, val] : node->children) {
        if (val->count >= k) {
            std::string newPrefix = currentPrefix + key;
            result.push_back(newPrefix);
            findCommonPrefixes(val, k, newPrefix, result);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;
    
    TrieNode* root = new TrieNode();

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        insert(root, s);
    }

    std::vector<std::string> result;
    findCommonPrefixes(root, k, "", result);

    std::cout << result.size() << "\n";
    for (const auto& prefix : result) {
        std::cout << prefix << "\n";
    }

    return 0;
}
