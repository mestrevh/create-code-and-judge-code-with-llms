/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n1, n2;
    if (!(cin >> n1)) return 0;

    while (cin >> n2 && n2 <= n1) {
        cout << "Digite um valor maior que o primeiro!" << endl;
    }

    long long sum = 0;
    bool found = false;

    for (long long i = n1; i <= n2; ++i) {
        if (is_prime(i)) {
            sum += i;
            found = true;
        }
    }

    if (!found) {
        cout << "Sem numeros primos no intervalo informado." << endl;
    } else {
        cout << sum << endl;
    }

    return 0;
}