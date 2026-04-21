/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline vector<int> countChars(const string& s) {
    vector<int> cnt(128, 0);
    for (unsigned char c : s) cnt[c]++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 0; tc < T; tc++) {
        int N;
        cin >> N;
        vector<string> recipes(N);
        for (int i = 0; i < N; i++) cin >> recipes[i];
        string available;
        cin >> available;

        vector<int> have = countChars(available);

        for (int i = 0; i < N; i++) {
            vector<int> need = countChars(recipes[i]);
            int ans = INT_MAX;
            for (int c = 0; c < 128; c++) {
                if (need[c] > 0) {
                    ans = min(ans, have[c] / need[c]);
                }
            }
            if (ans == INT_MAX) ans = 0;
            cout << ans << "\n";
            for (int c = 0; c < 128; c++) {
                if (need[c] > 0) have[c] -= ans * need[c];
            }
        }
        cout << "\n";
    }
    return 0;
}