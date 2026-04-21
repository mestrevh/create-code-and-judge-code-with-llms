/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> v;
    long long x;
    while (cin >> x) {
        v.push_back(x);
    }

    if (v.empty()) {
        return 0;
    }

    int n = v.size();

    vector<long long> invert_v;
    invert_v.reserve(n);
    for (int i = n - 1; i >= 0; --i) {
        invert_v.push_back(v[i]);
    }

    vector<long long> parimp_v;
    parimp_v.reserve(n);
    for (int i = 0; i < n; i += 2) {
        parimp_v.push_back(v[i]);
    }
    for (int i = 1; i < n; i += 2) {
        parimp_v.push_back(v[i]);
    }

    cout << "Invert:";
    for (int i = 0; i < n; ++i) {
        cout << " " << invert_v[i];
    }
    cout << "\n";

    cout << "ParImp:";
    for (int i = 0; i < n; ++i) {
        cout << " " << parimp_v[i];
    }
    cout << "\n";

    cout << "Soma:";
    for (int i = 0; i < n; ++i) {
        cout << " " << (invert_v[i] + parimp_v[i]);
    }
    cout << "\n";

    return 0;
}