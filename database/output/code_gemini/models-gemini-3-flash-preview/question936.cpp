/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Digite um numero inteiro:" << endl;

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    if (n <= 1) {
        cout << "Fatorial: 1" << endl;
        return 0;
    }

    vector<long long> digits;
    digits.push_back(1);

    const long long BASE = 1000000000LL;

    for (int i = 2; i <= n; ++i) {
        long long carry = 0;
        for (size_t j = 0; j < digits.size(); ++j) {
            long long val = digits[j] * i + carry;
            digits[j] = val % BASE;
            carry = val / BASE;
        }
        while (carry) {
            digits.push_back(carry % BASE);
            carry /= BASE;
        }
    }

    cout << "Fatorial: ";
    cout << digits.back();
    for (int i = (int)digits.size() - 2; i >= 0; --i) {
        cout << setfill('0') << setw(9) << digits[i];
    }
    cout << endl;

    return 0;
}