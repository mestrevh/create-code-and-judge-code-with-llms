/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

bool canForm(const vector<string>& words, const string& target, int pos, unordered_set<string>& memo) {
    if (pos == target.size()) return true;
    if (memo.count(to_string(pos))) return false;

    for (const string& word : words) {
        if (target.compare(pos, word.size(), word) == 0) {
            if (canForm(words, target, pos + word.size(), memo)) {
                return true;
            }
        }
    }
    memo.insert(to_string(pos));
    return false;
}

bool canFormSame(const vector<string>& setA, const vector<string>& setB, const string& target) {
    unordered_set<string> memoA, memoB;
    return canForm(setA, target, 0, memoA) && canForm(setB, target, 0, memoB);
}

int main() {
    int N1, N2;
    while (cin >> N1 >> N2) {
        vector<string> setA(N1), setB(N2);
        for (int i = 0; i < N1; i++) cin >> setA[i];
        for (int i = 0; i < N2; i++) cin >> setB[i];

        bool found = false;
        for (const string& wordA : setA) {
            for (const string& wordB : setB) {
                string target = wordA + wordB;
                if (canFormSame(setA, setB, target)) {
                    found = true;
                }
            }
        }

        cout << (found ? 'S' : 'N') << endl;
    }
    return 0;
}
