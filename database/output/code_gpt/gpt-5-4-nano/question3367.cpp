/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    if (n % 2 == 0) {
        cout << "O numero " << n << " eh par!";
    } else {
        cout << "O numero " << n << " eh impar!";
    }
    return 0;
}