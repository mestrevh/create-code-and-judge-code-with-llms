/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool divisivelPor(long long A, long long B) {
    return A % B == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    if (!(cin >> A >> B)) return 0;

    cout << (divisivelPor(A, B) ? "divisivel" : "nao divisivel");
    return 0;
}