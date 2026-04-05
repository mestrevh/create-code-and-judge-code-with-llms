/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> answers(50001, 0);
    if (50000 >= 1) answers[1] = 1;
    if (50000 >= 2) answers[2] = 6;

    for (int n = 3; n <= 50000; n++) {
        answers[n] = answers[n-1] + (n-1) * 2 + (n-2) * 2;
    }

    long long N;
    while (cin >> N) {
        if (N <= 0 || N > 50000) continue;
        cout << answers[(int)N] << "\n";
    }
    return 0;
}