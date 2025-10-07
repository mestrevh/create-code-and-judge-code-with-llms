/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

bool is_prime(int n) {
    n = abs(n);
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int count_divisors(int n) {
    n = abs(n);
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;
        long long reliability = 0;
        for (int i = 0; i < m; ++i) {
            int num;
            cin >> num;
            if (is_prime(num)) {
                reliability += 2 * num;
            } else {
                reliability += (num / 2.0) * count_divisors(num);
            }
        }

        if (reliability > pow(2, 11)) {
            cout << "Anão Paulo. babado." << endl;
        } else if (reliability > pow(2, 9)) {
            cout << "Para pow." << endl;
        } else if (reliability > 0) {
            cout << "Se isso não é mentira eu sou uma brastemp 4 portas" << endl;
        } else {
            cout << "que mentirada" << endl;
        }
    }

    return 0;
}
