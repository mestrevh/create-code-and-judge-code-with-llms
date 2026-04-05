/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void normalize(vector<long long>& v) {
    if (v.empty()) return;
    auto min_it = min_element(v.begin(), v.end());
    rotate(v.begin(), min_it, v.end());
}

void print_v(const vector<long long>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<long long> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    normalize(v);
    print_v(v);

    for (int i = 0; i < Q; ++i) {
        long long qi;
        if (!(cin >> qi)) break;

        long long n = (long long)v.size();
        if (n < 2) continue;

        long long idx = (qi % n + n) % n;
        long long next_idx = (idx + 1) % n;

        v[idx] += v[next_idx];
        v.erase(v.begin() + next_idx);

        normalize(v);
        print_v(v);
    }

    return 0;
}