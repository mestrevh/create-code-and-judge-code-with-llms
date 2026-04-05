/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    long long max_prime = -1;
    bool found = false;

    while (cin >> n && n != 404) {
        if (is_prime(n)) {
            if (!found || n > max_prime) {
                max_prime = n;
                found = true;
            }
        }
    }

    if (found) {
        cout << max_prime << endl;
    } else {
        cout << "SEM PRIMOS" << endl;
    }

    return 0;
}