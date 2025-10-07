/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void KMP(const string& s, const string& p) {
    int n = s.size();
    int m = p.size();
    
    vector<int> lps(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = lps[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        lps[i] = j;
    }

    j = 0;
    bool found = false;

    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = lps[j - 1];
        }
        if (s[i] == p[j]) {
            j++;
        }
        if (j == m) {
            cout << i - m + 1 << endl;
            found = true;
            j = lps[j - 1];
        }
    }

    if (!found) {
        cout << -1 << endl;
    }
}

int main() {
    string s, p;
    cin >> s >> p;
    KMP(s, p);
    return 0;
}
