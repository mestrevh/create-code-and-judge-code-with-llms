/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef long long ll;

ll factorial(int n) {
    if (n < 0) return 0;
    ll res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll total_sum = 0;
    int val;
    for (int i = 0; i < 5; ++i) {
        if (cin >> val) {
            if (val > 0 && val % 3 == 0) {
                total_sum += factorial(val);
            }
        }
    }

    cout << total_sum << endl;

    return 0;
}