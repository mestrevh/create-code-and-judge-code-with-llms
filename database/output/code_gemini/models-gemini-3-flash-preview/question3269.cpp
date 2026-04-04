/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/**
 * Common Prefixes
 * Problem: Find all prefixes of size >= 1 that appear in at least K of N strings.
 * Constraints: N, K <= 30,000, String length T <= 20.
 * Time Limit: 1 second.
 * Complexity: O(N * T * log(alphabet)) time and O(N * T) space.
 * Strategy: Use a Trie to store all string prefixes and count their occurrences.
 * Perform a lexicographical DFS traversal to collect and count prefixes appearing at least K times.
 */

struct TrieNode {
    map<unsigned char, int> children;
    int count;
    TrieNode() : count(0) {}
};

vector<TrieNode> trie;

/**
 * Inserts a string into the trie and increments the count for each prefix.
 * Because each prefix is unique for a given length within a single string,
 * the count for a node represents the number of strings containing that prefix.
 */
void insert(const string& s) {
    int curr = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        unsigned char c = (unsigned char)s[i];
        auto it = trie[curr].children.find(c);
        if (it == trie[curr].children.end()) {
            int next_node = (int)trie.size();
            trie.emplace_back();
            trie[curr].children[c] = next_node;
            curr = next_node;
        } else {
            curr = it->second;
        }
        trie[curr].count++;
    }
}

/**
 * Traverse the trie in lexicographical order (enforced by std::map) and
 * collect all prefixes with count >= K.
 */
void dfs(int u, int K, string& current_prefix, vector<string>& results) {
    for (auto const& entry : trie[u].children) {
        if (trie[entry.second].count >= K) {
            current_prefix.push_back((char)entry.first);
            results.push_back(current_prefix);
            dfs(entry.second, K, current_prefix, results);
            current_prefix.pop_back();
        }
    }
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    // Reserve space for worst-case nodes to avoid reallocations
    trie.reserve(600005);
    trie.emplace_back(); // Root node

    // Reading strings and building the Trie
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        if (!s.empty()) {
            insert(s);
        }
    }

    vector<string> results;
    // Upper bound for results count is the total number of trie nodes
    results.reserve(trie.size());
    string current_prefix = "";
    
    // Start DFS from root to find all prefixes common to at least K strings
    dfs(0, K, current_prefix, results);

    // Output the count of valid prefixes and each prefix in order
    cout << results.size() << "\n";
    for (const string& res : results) {
        cout << res << "\n";
    }

    return 0;
}