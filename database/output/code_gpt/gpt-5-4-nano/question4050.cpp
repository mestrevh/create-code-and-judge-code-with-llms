/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    if (!(cin >> N)) return 0;
    if (N >= 18) cout << "adulto";
    else if (N >= 10) cout << "adolescente";
    else if (N >= 0) cout << "crianca";
    return 0;
}