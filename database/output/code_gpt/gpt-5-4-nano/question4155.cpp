/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double a, b;
    if (!(cin >> a >> b)) return 0;

    double sum = a + b;
    double diff = a - b;
    double prod = a * b;
    double div = a / b;

    cout.setf(std::ios::fixed);
    cout << setprecision(2)
         << sum << ", " << diff << ", " << prod << ", " << div << "\n";
    return 0;
}