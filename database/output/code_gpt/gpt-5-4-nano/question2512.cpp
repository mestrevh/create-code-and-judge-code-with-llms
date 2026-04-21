/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double r;
    if (!(cin >> r)) return 0;

    const long double PI = 3.1415L;
    long double area = PI * r * r;

    cout.setf(std::ios::fixed);
    cout << setprecision(6) << (double)area;
    return 0;
}