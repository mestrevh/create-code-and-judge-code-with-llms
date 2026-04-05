/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> letters;
    string s;
    while (cin >> s) {
        if (!s.empty()) letters.push_back(s[0]);
    }

    sort(letters.begin(), letters.end());

    for (size_t i = 0; i < letters.size(); i++) {
        if (i) cout << ' ';
        cout << letters[i];
    }
    return 0;
}