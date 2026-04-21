/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void fibonacci_sem_retorno(int n) {
    long long a = 1, b = 1;
    for (int i = 1; i <= n; i++) {
        cout << a;
        if (i < n) cout << "\n";
        long long c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    fibonacci_sem_retorno(n);
    return 0;
}