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
    if (!(cin >> N)) return 0;
    vector<double> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];

    long long ans = 1;
    for (int i = 0; i < N; i++) {
        long long val = llround(T[i] * 10.0);
        ans = lcm(ans, val);
    }

    double result = ans / 10.0;
    cout << fixed << setprecision(1) << "O tempo para o alinhamento dos planetas e " << result << " minutos";
    return 0;
}