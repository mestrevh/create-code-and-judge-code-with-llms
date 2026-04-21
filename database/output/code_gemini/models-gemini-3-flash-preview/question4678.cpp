/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    if (n <= 0 || n > 10 || m <= 0 || m > 10) {
        cout << "Han??" << endl;
        return 0;
    }

    int prime_count = 0;
    for (int i = 0; i < n; ++i) {
        long long current_sum = 0;
        for (int j = 0; j < m; ++j) {
            long long val;
            if (cin >> val) {
                current_sum += val;
            }
        }
        if (is_prime(current_sum)) {
            prime_count++;
        }
    }

    if (prime_count * 2 > n) {
        cout << "Chama" << endl;
    } else {
        cout << "Não chama" << endl;
    }

    return 0;
}