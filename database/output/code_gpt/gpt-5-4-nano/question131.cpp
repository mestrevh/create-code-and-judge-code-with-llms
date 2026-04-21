/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string s;
    cin >> s;

    auto matches = [&](char a, char b) -> bool {
        if (a == 'w' || b == 'w') return true;
        return a == b;
    };

    int ans = 1;

    for (int i = 0; i < N; i++) {
        int cnt = 0;
        int cur = i;
        char c = s[cur];
        while (cnt < N && matches(s[cur], c)) {
            cnt++;
            cur = (cur + 1) % N;
            if (cnt == N) break;
        }
        ans = max(ans, cnt);
    }

    for (int k = 0; k < N; k++) {
        int left = k;
        int right = (k + 1) % N;
        int total = 0;

        char cL = s[left];
        int lenL = 0;
        while (lenL < N && matches(s[left], cL)) {
            lenL++;
            left = (left - 1 + N) % N;
            if (lenL == N) break;
        }

        char cR = s[right];
        int lenR = 0;
        while (lenR < N && matches(s[right], cR)) {
            lenR++;
            right = (right + 1) % N;
            if (lenR == N) break;
        }

        total = lenL + lenR;
        ans = max(ans, total);
    }

    if (N >= 2) ans = min(ans, N);

    cout << ans << "\n";
    return 0;
}