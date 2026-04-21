/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int G;
    char T;
    if (!(cin >> G)) return 0;
    cin >> T;

    const int N = 12;
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double x;
            cin >> x;
            if (i == G) sum += x;
        }
    }

    double res = (T == 'M') ? sum / N : sum;
    cout.setf(std::ios::fixed); 
    cout << setprecision(1) << res << "\n";
    return 0;
}