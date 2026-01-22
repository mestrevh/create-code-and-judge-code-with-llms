/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    while (Q--) {
        int type, L, R;
        cin >> type >> L >> R;
        if (type == 1) {
            S[L - 1] = cin.get();
        } else {
            vector<int> freq(26, 0);
            for (int i = L - 1; i < R; ++i) {
                freq[S[i] - 'a']++;
            }
            int odd_count = 0;
            for (int count : freq) {
                if (count % 2 != 0) odd_count++;
            }
            cout << (odd_count <= 1 ? "yes" : "no") << "\n";
        }
    }
    return 0;
}
