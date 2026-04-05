/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B, C;
    if (!(cin >> A >> B >> C)) return 0;
    int H, L;
    cin >> H >> L;
    
    int x[3] = {A, B, C};
    bool ok = false;
    
    for (int i = 0; i < 3 && !ok; i++) {
        int h = x[i];
        int w1 = x[(i + 1) % 3];
        int w2 = x[(i + 2) % 3];
        int minW = min(w1, w2);
        int maxW = max(w1, w2);
        if (h <= H) {
            if (minW <= L || maxW <= L) {
                ok = true;
            }
        }
        int h2 = x[(i + 1) % 3];
        int wA = x[(i + 2) % 3];
        int wB = x[i];
        minW = min(wA, wB);
        maxW = max(wA, wB);
        if (h2 <= H) {
            if (minW <= L || maxW <= L) {
                ok = true;
            }
        }
    }
    
    vector<int> d = {A, B, C};
    sort(d.begin(), d.end());
    vector<pair<int,int>> pairs;
    pairs.push_back({A,B});
    pairs.push_back({A,C});
    pairs.push_back({B,A});
    pairs.push_back({B,C});
    pairs.push_back({C,A});
    pairs.push_back({C,B});
    for (auto &p : pairs) {
        if ((p.first <= H && p.second <= L) || (p.first <= L && p.second <= H)) {
            ok = true;
            break;
        }
    }
    
    cout << (ok ? 'S' : 'N') << "\n";
    return 0;
}