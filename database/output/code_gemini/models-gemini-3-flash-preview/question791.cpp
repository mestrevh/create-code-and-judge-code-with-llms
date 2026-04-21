/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    long long k;
    if (cin >> n >> k) {
        long long sum_n = 0;
        for (char c : n) {
            sum_n += (c - '0');
        }

        // The superdigit of a number x is its digital root.
        // If x is formed by concatenating n, k times, the sum of digits of x 
        // is k multiplied by the sum of digits of n.
        // The digital root of x is the same as the digital root of its sum of digits.
        long long total_p = sum_n * k;

        if (total_p == 0) {
            cout << 0 << endl;
        } else {
            long long result = total_p % 9;
            if (result == 0) {
                result = 9;
            }
            cout << result << endl;
        }
    }

    return 0;
}