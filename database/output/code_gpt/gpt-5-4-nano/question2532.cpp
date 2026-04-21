/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B;
    cout << "Digite o valor de A:\n";
    if (!(cin >> A)) return 0;
    cout << "Digite o valor de B:\n";
    if (!(cin >> B)) return 0;
    cout << "O maior valor digitado foi: " << max(A, B);
    return 0;
}