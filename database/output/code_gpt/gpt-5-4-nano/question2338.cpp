/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

#define SWAP_MACRO(x, y) do { int tmp = (x); (x) = (y); (y) = tmp; } while(0)

int main() {
    int a, b;
    if (!(cin >> a >> b)) return 0;
    cout << "a: " << a << " b: " << b << "\n";
    SWAP_MACRO(a, b);
    cout << "a: " << a << " b: " << b;
    return 0;
}