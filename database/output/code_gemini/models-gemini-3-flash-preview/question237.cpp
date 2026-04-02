/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_NODES = 1000005;
int trie[MAX_NODES][26];
bool is_end_node[MAX_NODES];
int child_count[MAX_NODES];
int total_nodes;

void insert_word(const string& s) {
    int curr = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (!trie[curr][idx]) {
            total_nodes++;
            for (int i = 0; i < 26; ++i) trie[total_nodes][i] = 0;
            is_end_node[total_nodes] = false;
            child_count[total_nodes] = 0;
            
            trie[curr][idx] = total_nodes;
            child_count[curr]++;
        }
        curr = trie[curr][idx];
    }
    is_end_node[curr] = true;
}

int count_word_presses(const string& s) {
    int presses = 1;
    int curr = trie[0][s[0] - 'a'];
    
    for (int i = 1; i < (int)s.length(); ++i) {
        if (child_count[curr] > 1 || is_end_node[curr]) {
            presses++;
        }
        curr = trie[curr][s[i] - 'a'];
    }
    return presses;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N) {
        total_nodes = 0;
        for (int i = 0; i < 26; ++i) trie[0][i] = 0;
        is_end_node[0] = false;
        child_count[0] = 0;

        vector<string> words(N);
        for (int i = 0; i < N; ++i) {
            cin >> words[i];
            insert_word(words[i]);
        }

        long long total_presses = 0;
        for (int i = 0; i < N; ++i) {
            total_presses += count_word_presses(words[i]);
        }

        cout << fixed << setprecision(2) << (double)total_presses / N << "\n";
    }

    return 0;
}