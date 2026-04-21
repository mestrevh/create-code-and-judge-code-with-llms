/*
Código criado pelo gpt-5.4
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];

    vector<long long> leftMax(N), rightMax(N);
    leftMax[0] = H[0];
    for (int i = 1; i < N; ++i) leftMax[i] = max(leftMax[i - 1], H[i]);

    rightMax[N - 1] = H[N - 1];
    for (int i = N - 2; i >= 0; --i) rightMax[i] = max(rightMax[i + 1], H[i]);

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        long long waterLevel = min(leftMax[i], rightMax[i]);
        if (waterLevel - H[i] >= 1) ++ans;
    }

    cout << ans << '\n';
    return 0;
}