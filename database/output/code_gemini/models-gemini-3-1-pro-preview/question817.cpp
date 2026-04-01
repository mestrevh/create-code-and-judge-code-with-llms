/*
Código criado pelo models/gemini-3.1-pro-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    if (N <= 2) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> suff(N);
    suff[N - 1] = H[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        suff[i] = max(suff[i + 1], H[i]);
    }

    int ans = 0;
    int pref_max = H[0];
    for (int i = 1; i < N - 1; ++i) {
        if (pref_max > H[i] && suff[i + 1] > H[i]) {
            ans++;
        }
        if (H[i] > pref_max) {
            pref_max = H[i];
        }
    }

    cout << ans << "\n";
    return 0;
}