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

    if (n < 4) {
        cout << "N\n";
        return 0;
    }

    bool composite = false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            composite = true;
            break;
        }
    }

    if (composite) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

    return 0;
}