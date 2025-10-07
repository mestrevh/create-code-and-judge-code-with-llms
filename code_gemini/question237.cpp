/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    int childCount;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
        childCount = 0;
    }
};

void insert(TrieNode* root, const std::string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!current->children[index]) {
            current->children[index] = new TrieNode();
            current->childCount++;
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

int countKeystrokes(TrieNode* root, const std::string& word) {
    int strokes = 0;
    TrieNode* current = root;
    for (char ch : word) {
        if (current == root || current->childCount > 1 || current->isEndOfWord) {
            strokes++;
        }
        int index = ch - 'a';
        current = current->children[index];
    }
    return strokes;
}

void deleteTrie(TrieNode* node) {
    if (!node) {
        return;
    }
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            deleteTrie(node->children[i]);
        }
    }
    delete node;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n) {
        TrieNode* root = new TrieNode();
        std::vector<std::string> words(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> words[i];
            insert(root, words[i]);
        }

        long long totalKeystrokes = 0;
        for (const auto& word : words) {
            totalKeystrokes += countKeystrokes(root, word);
        }

        double average = static_cast<double>(totalKeystrokes) / n;

        std::cout << std::fixed << std::setprecision(2) << average << '\n';

        deleteTrie(root);
    }

    return 0;
}
