/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string S;
        cin >> S;
        int N;
        cin >> N;

        array<string, 256> mp;
        for (int i = 0; i < 256; i++) mp[i].clear();

        for (int i = 0; i < N; i++) {
            string C, A;
            cin >> C >> A;
            mp[(unsigned char)C[0]] = A;
        }

        string out;
        out.reserve(S.size() * 10);

        for (size_t i = 0; i < S.size(); ) {
            if (S[i] == '*') {
                char c = (i + 1 < S.size() ? S[i + 1] : 0);
                string rep = mp[(unsigned char)c];
                if (!rep.empty()) out += rep;
                else out.push_back('*');
                i += 2;
            } else {
                out.push_back(S[i]);
                i++;
            }
        }

        cout << out << "\n";
    }
    return 0;
}