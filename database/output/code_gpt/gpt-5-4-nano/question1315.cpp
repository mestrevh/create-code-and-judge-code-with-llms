/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long year;
    if (!(cin >> year)) return 0;

    bool leap = false;
    if (year % 400 == 0) leap = true;
    else if (year % 100 == 0) leap = false;
    else if (year % 4 == 0) leap = true;
    else leap = false;

    if (leap) cout << "Bissexto";
    else cout << "Nao bissexto";
    return 0;
}