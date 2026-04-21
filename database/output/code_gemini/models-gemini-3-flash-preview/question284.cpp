/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    if (n == 0) {
        cout << 10 << endl;
        return 0;
    }

    if (n < 10) {
        cout << n << endl;
        return 0;
    }

    vector<int> digits;
    for (int i = 9; i >= 2; --i) {
        while (n % i == 0) {
            digits.push_back(i);
            n /= i;
        }
    }

    if (n > 1) {
        cout << -1 << endl;
    } else {
        sort(digits.begin(), digits.end());
        for (int d : digits) {
            cout << d;
        }
        cout << endl;
    }

    return 0;
}