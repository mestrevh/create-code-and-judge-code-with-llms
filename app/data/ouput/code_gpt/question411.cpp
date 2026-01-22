/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

void backtrack(string &src, string &dst, string &current, int i, int j, set<string> &results) {
    if (j == dst.size()) {
        if (i == src.size()) results.insert(current);
        return;
    }
    
    if (i < src.size()) {
        current.push_back('i');
        backtrack(src, dst, current, i + 1, j, results);
        current.pop_back();
    }
    
    if (!current.empty() && current.back() == 'i') {
        char last = current.back();
        current.pop_back();
        if (j < dst.size() && (dst[j] == src[i - 1])) {
            backtrack(src, dst, current, i - 1, j + 1, results);
        }
        current.push_back(last);
    }
}

vector<string> generateSequences(string src, string dst) {
    set<string> results;
    string current;
    backtrack(src, dst, current, 0, 0, results);
    vector<string> sequences(results.begin(), results.end());
    sort(sequences.begin(), sequences.end());
    return sequences;
}

int main() {
    string src, dst;
    while (getline(cin, src) && getline(cin, dst)) {
        vector<string> sequences = generateSequences(src, dst);
        cout << "[\n";
        for (const string &seq : sequences) {
            for (size_t i = 0; i < seq.size(); ++i) {
                cout << seq[i];
                if (i < seq.size() - 1) cout << " ";
            }
            cout << "\n";
        }
        cout << "]\n";
    }
    return 0;
}
