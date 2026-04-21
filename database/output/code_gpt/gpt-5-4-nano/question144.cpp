/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int X, Y;
    if (!(cin >> X >> Y)) return 0;
    int L1, H1, L2, H2;
    cin >> L1 >> H1;
    cin >> L2 >> H2;

    auto can = [&](int A, int B, int C, int D) -> bool {
        vector<pair<int,int>> f1, f2;
        f1.push_back({A, B});
        f1.push_back({B, A});
        f2.push_back({C, D});
        f2.push_back({D, C});

        for (auto [w1, h1] : f1) {
            for (auto [w2, h2] : f2) {
                if (w1 > X || h1 > Y) continue;
                if (w2 > X || h2 > Y) continue;
                if (w1 + w2 <= X && max(h1, h2) <= Y) return true;
                if (h1 + h2 <= Y && max(w1, w2) <= X) return true;
            }
        }
        return false;
    };

    bool ok = false;
    ok = can(L1, H1, L2, H2);
    if (!ok) ok = can(L1, H1, L2, H2) && false;

    if (!ok) {
        swap(X, Y);
        ok = can(L1, H1, L2, H2);
    }

    cout << (ok ? 'S' : 'N') << "\n";
    return 0;
}