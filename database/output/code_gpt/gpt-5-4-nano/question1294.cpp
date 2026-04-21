/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long binToDecRec(const string& s, int i, long long val) {
    if (i == (int)s.size()) return val;
    if (s[i] != '0' && s[i] != '1') return 0;
    return binToDecRec(s, i + 1, val * 2 + (s[i] - '0'));
}

string decToBinRec(unsigned long long n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    string prev = decToBinRec(n / 2);
    prev.push_back((n % 2) ? '1' : '0');
    return prev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    for (int k = 0; k < N; k++) {
        string O;
        string X;
        cin >> O >> X;

        if (O == "dec") {
            bool ok = true;
            if (X.empty()) ok = false;
            for (char c : X) if (!(c == '-' || isdigit((unsigned char)c))) ok = false;
            if (!ok) {
                cout << "comando invalido.\n";
                continue;
            }
            long long val = 0;
            try {
                size_t idx = 0;
                val = stoll(X, &idx);
                if (idx != X.size()) ok = false;
            } catch (...) {
                ok = false;
            }
            if (!ok || val < 0) {
                cout << "comando invalido.\n";
                continue;
            }
            cout << decToBinRec((unsigned long long)val) << "\n";
        } else if (O == "bin") {
            bool ok = !X.empty();
            for (char c : X) if (c != '0' && c != '1') ok = false;
            if (!ok) {
                cout << "comando invalido.\n";
                continue;
            }
            long long val = binToDecRec(X, 0, 0);
            cout << val << "\n";
        } else {
            cout << "comando invalido.\n";
        }
    }
    return 0;
}