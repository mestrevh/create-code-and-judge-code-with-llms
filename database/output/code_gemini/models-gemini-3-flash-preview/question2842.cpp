/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    cout << "Digite um numero inteiro:" << endl;

    if (n == 0) {
        cout << "O numero nao possui divisores multiplos de 3" << endl;
        return 0;
    }

    if (n < 0) n = -n;

    long long count = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i % 3 == 0) {
                count++;
            }
            if (i * i != n) {
                if ((n / i) % 3 == 0) {
                    count++;
                }
            }
        }
    }

    if (count == 0) {
        cout << "O numero nao possui divisores multiplos de 3" << endl;
    } else {
        cout << "Quantidade de divisores divisiveis por 3: " << count << endl;
    }

    return 0;
}