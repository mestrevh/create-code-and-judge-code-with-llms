/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long birthYear, currentYear;
    if (!(cin >> birthYear >> currentYear)) return 0;
    cout << (currentYear - birthYear) << "\n";
    return 0;
}