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
    bool firstOutput = true;
    while ( (cin >> N) ) {
        vector<pair<int,int>> segs;
        segs.reserve(N);
        for (int i = 0; i < N; i++) {
            int A, B;
            cin >> A >> B;
            segs.push_back({A, B});
        }

        sort(segs.begin(), segs.end(), [](const auto& x, const auto& y){
            if (x.second != y.second) return x.second < y.second;
            return x.first < y.first;
        });

        int ans = 0;
        int lastPos = INT_MIN;
        for (auto &s : segs) {
            if (ans == 0 || s.first > lastPos) {
                ans++;
                lastPos = s.second;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}