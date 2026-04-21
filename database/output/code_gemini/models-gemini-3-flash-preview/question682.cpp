/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            int a;
            if (cin >> a) {
                // A regular polygon with n sides has an interior angle of A = (n-2)*180/n
                // A = 180 - 360/n
                // 180 - A = 360/n
                // n = 360 / (180 - A)
                // For a regular polygon to exist, n must be an integer and n >= 3.
                // The condition for n being an integer is that (180 - A) must divide 360.
                // Since 0 < A < 180, (180 - A) is between 1 and 179.
                // If 360 % (180 - a) == 0, then n = 360 / (180 - a) is an integer.
                // If n is an integer, then n = 360 / (180 - a). Since (180 - a) <= 179,
                // n will always be >= 360 / 179, which is approx 2.011.
                // The only integer n < 3 is 2, which would require 360 / (180 - a) = 2,
                // meaning 180 - a = 180, so a = 0. However, the problem says a > 0.
                // Therefore, 360 % (180 - a) == 0 is a sufficient and necessary condition.
                if (360 % (180 - a) == 0) {
                    cout << "SIM\n";
                } else {
                    cout << "NAO\n";
                }
            }
        }
    }

    return 0;
}