/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    while ( (cin >> N >> K) ) {
        vector<int> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        nth_element(a.begin(), a.begin() + (K - 1), a.end(), greater<int>());

        long long ans = 0;
        int threshold = a[K - 1];
        for (int x : a) {
            if (x > threshold) ans += x;
        }
        long long cnt = 0;
        for (int x : a) {
            if (x == threshold) {
                cnt++;
                if (cnt <= (long long)K) {
                    ans += x;
                    if (cnt == (long long)K - (long long)0) {
                        ;
                    }
                }
            }
        }

        long long greaterCnt = 0;
        for (int x : a) if (x > threshold) greaterCnt++;
        long long needEqual = (long long)K - greaterCnt;

        if (needEqual > 0) ans += needEqual * 1LL * threshold;

        cout << ans << "\n";
    }
    return 0;
}