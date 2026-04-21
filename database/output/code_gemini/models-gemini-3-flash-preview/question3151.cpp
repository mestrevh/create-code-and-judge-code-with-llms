/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * A person is INFECTADO if there exist three integers a, b, c such that:
 * 1. a * b * c = Exam Number (N)
 * 2. a + b + c = 19
 * 
 * Given N is in the range [0, 100], we can precompute which values of N
 * satisfy these conditions by iterating through possible values of a and b,
 * calculating c = 19 - a - b, and checking the product.
 * 
 * Integers a, b, c can be positive, negative, or zero.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Precomputation table for N in range [0, 100]
    bool infected[101];
    for (int i = 0; i <= 100; ++i) {
        infected[i] = false;
    }

    // Iterate through a and b to find valid products
    // Range [-150, 150] is more than sufficient to find all products N <= 100
    // given the constraint a + b + c = 19.
    for (int a = -150; a <= 150; ++a) {
        for (int b = -150; b <= 150; ++b) {
            int c = 19 - a - b;
            long long prod = (long long)a * b * c;
            if (prod >= 0 && prod <= 100) {
                infected[(int)prod] = true;
            }
        }
    }

    int n;
    // Process input until -1
    while (cin >> n && n != -1) {
        // According to problem constraints 0 <= n <= 100
        if (n >= 0 && n <= 100) {
            if (infected[n]) {
                cout << "INFECTADO\n";
            } else {
                cout << "SAFE\n";
            }
        } else {
            // Safety fallback for unexpected input values
            cout << "SAFE\n";
        }
    }

    return 0;
}