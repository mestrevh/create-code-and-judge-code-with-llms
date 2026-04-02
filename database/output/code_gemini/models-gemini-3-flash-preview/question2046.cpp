/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Checks if a number x is prime.
 * @param x The number to be checked.
 * @return True if x is prime, False otherwise.
 */
bool eh_primo(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

/**
 * Returns the smallest prime number greater than or equal to y.
 * @param y The starting number.
 * @return The next prime number.
 */
int proximo_primo(int y) {
    while (!eh_primo(y)) {
        y++;
    }
    return y;
}

/**
 * Calculates the factorial of z.
 * Using double to prevent overflow and facilitate floating point division.
 * @param z The number.
 * @return The factorial of z.
 */
double fatorial(int z) {
    double f = 1.0;
    for (int i = 2; i <= z; i++) {
        f *= i;
    }
    return f;
}

int main() {
    // Standard I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    double soma = 0.0;
    for (int i = 1; i <= n; i++) {
        int divisor;
        
        // As per problem description, the first term has divisor 1.
        // Starting from the second term, the divisor is the next prime >= i.
        if (i == 1) {
            divisor = 1;
        } else {
            divisor = proximo_primo(i);
        }

        // Print term in format k!/p
        cout << i << "!/" << divisor;
        if (i < n) {
            cout << " + ";
        }

        // Accumulate sum
        soma += fatorial(i) / (double)divisor;
    }

    // Output formatting: 2 decimal places as requested
    cout << fixed << setprecision(2) << "\n" << soma << endl;

    return 0;
}