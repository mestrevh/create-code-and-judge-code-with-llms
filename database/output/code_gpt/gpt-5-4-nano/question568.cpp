/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long year;
    if (!(cin >> year)) return 0;

    bool leap = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
    if (leap) cout << "BISSEXTO";
    else cout << "NAOBISSEXTO";
    return 0;
}