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
    double A;
    if (!(cin >> N >> A)) return 0;

    double result = 0.0;
    switch (N) {
        case 1:
            result = pow(2.0, A);
            break;
        case 2:
            result = sqrt(A);
            break;
        case 3:
            result = fabs(A);
            break;
        case 4:
            result = log(A) / log(2.0);
            break;
        default:
            result = 0.0;
            break;
    }

    cout << fixed << setprecision(2) << result << "\n";
    return 0;
}