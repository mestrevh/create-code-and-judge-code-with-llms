/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double a1, a2;
    cout << "Digite o 1° ângulo:\n";
    if (!(cin >> a1)) return 0;
    cout << "Digite o 2° ângulo:\n";
    if (!(cin >> a2)) return 0;
    
    double a3 = 180.0 - a1 - a2;
    cout << fixed << setprecision(2) << "O terceiro ângulo é: " << a3;
    return 0;
}