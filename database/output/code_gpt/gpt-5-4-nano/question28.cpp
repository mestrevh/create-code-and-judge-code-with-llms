/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int a = n / 10;
    int b = n % 10;
    int inv = b * 10 + a;

    cout << inv << "\n";
    return 0;
}