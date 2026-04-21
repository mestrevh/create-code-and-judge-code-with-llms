/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double X;
    int C;
    if (!(cin >> X)) return 0;
    if (!(cin >> C)) return 0;

    long double V = 0.0L;
    long double fact = 1.0L;

    int term = 0;
    int denomIndex = 1;

    for (int n = 0; n < C; n++) {
        while (denomIndex <= 2*n + 1) {
            fact *= (long double)denomIndex;
            denomIndex++;
        }
        long double num = powl(X, 2*n + 1);
        long double termValue = num / fact;
        if (n % 2 == 0) V += termValue;
        else V -= termValue;
    }

    V = fabsl(V);
    cout.setf(std::ios::fixed);
    cout << setprecision(3) << (double)V << "\n";
    return 0;
}