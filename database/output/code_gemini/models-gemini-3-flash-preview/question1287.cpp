/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

long long multiply_recursive(long long a, long long b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    long long half = multiply_recursive(a, b / 2);
    if (b % 2 == 0) {
        return half + half;
    } else {
        return half + half + a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b;
    while (cin >> a >> b) {
        if (b == 0) {
            cout << 0 << "\n";
        } else if (b < 0) {
            cout << -multiply_recursive(a, -b) << "\n";
        } else {
            cout << multiply_recursive(a, b) << "\n";
        }
    }
    return 0;
}