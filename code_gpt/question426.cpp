/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

bool canForm(const vector<string>& words, const string& target) {
    int n = target.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; ++i) {
        if (!dp[i]) continue;
        for (const string& word : words) {
            int wordLen = word.size();
            if (i + wordLen <= n && target.substr(i, wordLen) == word) {
                dp[i + wordLen] = true;
            }
        }
    }
    return dp[n];
}

int main() {
    int n1, n2;
    while (cin >> n1 >> n2) {
        vector<string> setA(n1), setB(n2);
        for (int i = 0; i < n1; ++i) cin >> setA[i];
        for (int i = 0; i < n2; ++i) cin >> setB[i];

        string target;
        cin >> target;

        bool canFormA = canForm(setA, target);
        bool canFormB = canForm(setB, target);

        cout << (canFormA && canFormB ? 'S' : 'N') << endl;
    }
    return 0;
}
