/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K;
    if (!(cin >> K)) return 0;
    while (K--) {
        int N;
        cin >> N;
        string secret;
        cin >> secret;

        vector<int> sc(10, 0);
        for (char c : secret) sc[c - '0']++;

        while (true) {
            string guess;
            cin >> guess;
            if (!cin) return 0;
            bool allZero = true;
            for (char c : guess) if (c != '0') { allZero = false; break; }
            if (allZero) break;

            int E = 0;
            vector<int> remS(10, 0), remG(10, 0);

            for (int i = 0; i < N; i++) {
                int s = secret[i] - '0';
                int g = guess[i] - '0';
                if (s == g) E++;
                else {
                    remS[s]++;
                    remG[g]++;
                }
            }

            int B = 0;
            for (int d = 0; d <= 9; d++) B += min(remS[d], remG[d]);

            cout << "(" << E << "," << B << ")\n";
        }
    }
    return 0;
}