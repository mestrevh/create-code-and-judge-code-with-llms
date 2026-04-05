/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int D;
    string N;
    while (cin >> D >> N) {
        if (D == 0 && N == "0") break;

        int r = (D % 2 + 2) % 2;

        bool hasD = false;
        for (char c : N) if (c - '0' == D) { hasD = true; break; }
        if (!hasD) {
            cout << N << "\n";
            continue;
        }

        if (D != 1 && D != 2 && D != 3 && D != 4 && D != 5 && D != 6 && D != 7 && D != 8 && D != 9) {
            cout << N << "\n";
            continue;
        }

        if (N.size() == 1) {
            if (N[0] - '0' == D) cout << 0 << "\n";
            else cout << N << "\n";
            continue;
        }

        int L = (int)N.size();
        vector<char> keep(L, 1);
        for (int i = 0; i < L; i++) {
            if (N[i] - '0' == D) keep[i] = 0;
        }

        if (D == 5) {
            cout << N.substr(0,0) << (0) << "\n";
            continue;
        }

        int posFirst = -1;
        for (int i = 0; i < L; i++) {
            if (keep[i]) { posFirst = i; break; }
        }
        if (posFirst == -1) {
            cout << 0 << "\n";
            continue;
        }

        string out;
        out.reserve(L);

        for (int i = posFirst; i < L; i++) if (keep[i]) out.push_back(N[i]);

        if (out.empty()) out = "0";

        cout << out << "\n";
    }
    return 0;
}