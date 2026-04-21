/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    if (!getline(cin, text)) return 0;
    if (!getline(cin, pattern)) {
        // If pattern is missing, we check if it was intended to be empty or just missing
        // In most competitive scenarios, there's always a second line
        return 0;
    }

    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }

    // KMP Algorithm for O(N + M) substring counting
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        pi[i] = j;
    }

    int count = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            count++;
            j = pi[j - 1];
        }
    }

    cout << count << endl;

    return 0;
}