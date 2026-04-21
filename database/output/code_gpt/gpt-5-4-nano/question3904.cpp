/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Item {
    long long vol;
    long long id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<Item> a;
        a.reserve(N);
        for (int i = 0; i < N; i++) {
            long long I;
            long long H, W, L;
            cin >> I >> H >> W >> L;
            long long vol = H * W * L;
            a.push_back({vol, I});
        }

        nth_element(a.begin(), a.begin() + K, a.end(),
                    [](const Item& x, const Item& y) {
                        if (x.vol != y.vol) return x.vol > y.vol;
                        return x.id < y.id;
                    });

        sort(a.begin(), a.begin() + K, [](const Item& x, const Item& y) {
            if (x.vol != y.vol) return x.vol > y.vol;
            return x.id < y.id;
        });

        vector<long long> ids;
        ids.reserve(K);
        for (int i = 0; i < K; i++) ids.push_back(a[i].id);
        sort(ids.begin(), ids.end());

        for (int i = 0; i < K; i++) {
            if (i) cout << ' ';
            cout << ids[i];
        }
        cout << "\n";
    }
    return 0;
}