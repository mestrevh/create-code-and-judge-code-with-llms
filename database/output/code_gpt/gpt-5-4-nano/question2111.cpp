/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<double> a;
    double x;
    while (cin >> x) a.push_back(x);

    double sum = 0.0;
    long long cnt = 0;

    for (double v : a) {
        if (v > 0) {
            long long iv = llround(v);
            if (fabs(v - (double)iv) < 1e-9 && iv % 2 == 0) {
                sum += v;
                cnt++;
            }
        }
    }

    if (cnt == 0) {
        cout << -1 << "\n";
    } else {
        cout.setf(std::ios::fixed);
        cout << setprecision(2) << (sum / cnt) << "\n";
    }
    return 0;
}