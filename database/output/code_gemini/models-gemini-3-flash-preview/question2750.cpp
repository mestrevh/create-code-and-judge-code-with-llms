/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

bool is_perfect(long long x) {
    if (x <= 1) return false;
    long long sum = 1;
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            sum += i;
            if (i * i != x) {
                sum += x / i;
            }
        }
    }
    return sum == x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        long long x;
        cin >> x;
        if (is_perfect(x)) {
            cout << x << " eh perfeito" << "\n";
        } else {
            cout << x << " nao eh perfeito" << "\n";
        }
    }

    return 0;
}