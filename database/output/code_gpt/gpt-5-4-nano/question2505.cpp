/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long P;
    int X;
    if (!(cin >> P)) return 0;
    cin >> X;

    vector<long long> a(X), b(X);
    for (int i = 0; i < X; i++) cin >> a[i];
    for (int i = 0; i < X; i++) cin >> b[i];

    string s;
    getline(cin, s);
    if (!cin) return 0;
    getline(cin, s);
    while (s.size() == 0 && cin) getline(cin, s);

    long long scoreJ = 0, scoreC = 0;
    long long idxSumJ = 0, idxSumC = 0;
    int goalsJ = 0, goalsC = 0;

    for (int t = 0; t < (int)s.size(); t++) {
        char ch = s[t];
        if (ch != 'J' && ch != 'C') continue;

        int pos = goalsJ + goalsC + 1;
        if (ch == 'J') {
            long long val = a[(pos - 1) % X];
            scoreJ += val;
            goalsJ++;
            idxSumJ += ((pos - 1) % X) + 1;
        } else {
            long long val = b[(pos - 1) % X];
            scoreC += val;
            goalsC++;
            idxSumC += ((pos - 1) % X) + 1;
        }

        if (scoreJ >= P || scoreC >= P) break;
    }

    if (idxSumJ >= P || idxSumC >= P) {
        cout << "joey, essas regras estao piores que as do Fireball";
        return 0;
    }

    if (scoreJ >= P) {
        cout << "Well, you suck! But at least you suck at a man's game now Joey: ";
        cout << scoreJ << " (" << goalsJ << ")\n";
        cout << "Chandler: " << scoreC << " (" << goalsC << ")";
    } else {
        cout << "Good game, good game, good game Chandler: ";
        cout << scoreC << " (" << goalsC << ")\n";
        cout << "Joey: " << scoreJ << " (" << goalsJ << ")";
    }

    return 0;
}