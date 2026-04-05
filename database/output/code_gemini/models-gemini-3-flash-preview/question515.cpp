/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hash table size m. A prime number larger than the maximum number of distinct words (10,000).
const int M = 30011;

struct Entry {
    string key;
    vector<int> lines;
    bool occupied = false;
};

// Global hash table
Entry table[M];

// Compute code(W) mod m using Horner's Method.
// code(W) = sum(W[i] * 26^(L-1-i)). Modular arithmetic ensures we avoid overflow.
int getHash(const string& s) {
    long long h = 0;
    for (char c : s) {
        h = (h * 26 + (c - 'a')) % M;
    }
    return (int)(h % M);
}

// Insert word into the hash table with closed addressing (linear probing).
void insert(const string& word, int lineNum) {
    int idx = getHash(word);
    // Linear probing search
    while (table[idx].occupied && table[idx].key != word) {
        idx = (idx + 1) % M;
    }
    // If slot is empty, initialize it
    if (!table[idx].occupied) {
        table[idx].occupied = true;
        table[idx].key = word;
    }
    // Only store line number if it's new for this word (ascending order guaranteed by processing)
    if (table[idx].lines.empty() || table[idx].lines.back() != lineNum) {
        table[idx].lines.push_back(lineNum);
    }
}

// Search for a word in the hash table.
vector<int>* findEntry(const string& word) {
    int idx = getHash(word);
    int startIdx = idx;
    while (table[idx].occupied) {
        if (table[idx].key == word) return &table[idx].lines;
        idx = (idx + 1) % M;
        if (idx == startIdx) break; // Table full
    }
    return nullptr;
}

int main() {
    // Optimize C++ standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    // The first line is always "$TEXTO"
    if (!getline(cin, line)) return 0;

    int lineNum = 0;
    // Process the text section line by line
    while (getline(cin, line) && line != "$CONSULTAS") {
        lineNum++;
        string word = "";
        for (char c : line) {
            // Words consist of lowercase a-z. Delimiters are everything else.
            if (c >= 'a' && c <= 'z') {
                word += c;
            } else {
                if (!word.empty()) {
                    insert(word, lineNum);
                    word = "";
                }
            }
        }
        if (!word.empty()) {
            insert(word, lineNum);
        }
    }

    // Process the query section
    while (cin >> line) {
        cout << line << ":";
        vector<int>* occurrences = findEntry(line);
        if (occurrences) {
            for (int ln : *occurrences) {
                cout << " " << ln;
            }
        }
        cout << "\n";
    }

    return 0;
}

