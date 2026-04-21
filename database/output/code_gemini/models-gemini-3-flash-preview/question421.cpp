/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    bool first_case = true;

    while (cin >> n && n != 0) {
        if (!first_case) {
            cout << "\n";
        }
        first_case = false;

        bool found = false;
        // The smallest possible 5-digit number using unique digits is 01234
        // The largest is 98765. 
        // abcde = n * fghij. Since abcde <= 98765, fghij <= 98765 / n.
        for (int f = 1234; f <= 98765 / n; ++f) {
            int a = f * n;
            
            int mask = 0;
            // Extract digits of denominator f (fghij)
            if (f < 10000) mask |= (1 << 0); // leading zero
            int temp = f;
            while (temp > 0) {
                mask |= (1 << (temp % 10));
                temp /= 10;
            }
            
            // Extract digits of numerator a (abcde)
            if (a < 10000) mask |= (1 << 0); // leading zero
            temp = a;
            while (temp > 0) {
                mask |= (1 << (temp % 10));
                temp /= 10;
            }
            
            // If the mask has all 10 bits set, it means each digit 0-9 was used exactly once.
            // (1 << 10) - 1 = 1023
            if (mask == 1023) {
                found = true;
                cout << setfill('0') << setw(5) << a << " / "
                     << setfill('0') << setw(5) << f << " = " << n << "\n";
            }
        }

        if (!found) {
            cout << "There are no solutions for " << n << ".\n";
        }
    }

    return 0;
}