/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n <= 0 || n > 10 || m <= 0 || m > 10) {
        cout << "Han??" << endl;
        return 0;
    }

    vector<vector<int>> fights(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> fights[i][j];
        }
    }

    int prime_count = 0;
    for (int i = 0; i < n; ++i) {
        int total_fights = 0;
        for (int j = 0; j < m; ++j) {
            total_fights += fights[i][j];
        }
        if (is_prime(total_fights)) {
            prime_count++;
        }
    }

    if (prime_count > n / 2) {
        cout << "Chama" << endl;
    } else {
        cout << "Não chama" << endl;
    }

    return 0;
}
