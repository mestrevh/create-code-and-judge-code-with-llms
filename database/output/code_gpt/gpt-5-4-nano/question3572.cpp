/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    long long years = n / 365;
    n %= 365;
    long long weeks = n / 7;
    long long days = n % 7;
    cout << years << " ano(s), " << weeks << " semana(s) e " << days << " dia(s)";
    return 0;
}