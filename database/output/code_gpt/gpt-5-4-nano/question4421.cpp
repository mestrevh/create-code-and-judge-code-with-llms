/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(long long x) {
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    long long A, B;
    int sapo = 0, shuas = 0, empates = 0;

    auto moveFrom = [&](long long v) -> int {
        if (isPrime(v)) return 2;      
        if (v % 2 == 0) return 0;      
        return 1;                      
    };

    auto decide = [&](int a, int b) {
        if (a == b) return 0;
        if ((a == 0 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 0)) return 1;
        return -1;
    };

    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        int mA = moveFrom(A);
        int mB = moveFrom(B);
        int r = decide(mA, mB);
        if (r == 1) sapo++;
        else if (r == -1) shuas++;
        else empates++;
    }

    if (sapo > shuas) {
        cout << "Sapo sopa esta de boa na lagoa!";
    } else if (shuas > sapo) {
        cout << "Testemunhe a verdadeira forca!";
    } else {
        cout << "Impending doom approaches...";
    }
    return 0;
}