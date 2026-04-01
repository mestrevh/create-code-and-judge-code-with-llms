/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

int solve(vector<int>& v) {
    if (v.empty()) return 0;
    int n = (int)v.size();
    if (n == 1) return 1;
    int p_val;
    if (n < 3) {
        p_val = v[0];
    } else {
        int a = v[0];
        int b = v[(n - 1) / 2];
        int c = v[n - 1];
        if ((a <= b && b <= c) || (c <= b && b <= a)) p_val = b;
        else if ((b <= a && a <= c) || (c <= a && a <= b)) p_val = a;
        else p_val = c;
    }
    vector<int> L, R;
    L.reserve(n / 2);
    R.reserve(n / 2);
    for (int x : v) {
        if (x < p_val) L.push_back(x);
        else if (x > p_val) R.push_back(x);
    }
    vector<int>().swap(v);
    int hl = solve(L);
    vector<int>().swap(L);
    int hr = solve(R);
    vector<int>().swap(R);
    return 1 + max(hl, hr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    ll M, seedD, A, C;
    if (!(cin >> N >> M >> seedD >> A >> C)) return 0;

    vector<int> D(N);
    D[0] = (int)seedD;
    for (int i = 1; i < N; ++i) {
        D[i] = (int)(((ll)A * D[i - 1] + C) % M);
    }

    set<int> scene(D.begin(), D.end());
    int h = solve(D);
    cout << "0: " << h << "\n";

    int Q;
    if (!(cin >> Q)) return 0;
    for (int j = 1; j <= Q; ++j) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            int val;
            cin >> val;
            if (scene.find(val) != scene.end()) {
                cout << j << ": 0\n";
            } else {
                scene.insert(val);
                cout << j << ": 1\n";
            }
        } else if (cmd == "DEL") {
            int L, R;
            cin >> L >> R;
            auto it_low = scene.lower_bound(L);
            auto it_high = scene.upper_bound(R);
            int count = 0;
            count = (int)distance(it_low, it_high);
            scene.erase(it_low, it_high);
            cout << j << ": " << count << "\n";
        }
    }

    return 0;
}