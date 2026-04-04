/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Problem: Calculate Right Riemann Sum for f(x) = x^2 in [A, B] with N rectangles.
 * Formula: Sum = delta_x * sum_{i=1}^{N} (A + i * delta_x)^2
 * where delta_x = (B - A) / N.
 * Compare the result with Taylor's value C.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double a, b, n, c;
    
    // Reading input. cin handles spaces and newlines automatically.
    // Format: A B N (line 1), C (line 2)
    if (!(cin >> a >> b >> n >> c)) {
        return 0;
    }

    // Calculating step size (width of rectangles)
    long double dx = (b - a) / n;
    long double riemann_sum = 0;
    
    // Casting N to a long long to handle it as an iteration count
    long long iterations = (long long)(n + 0.5);

    // Right Riemann Sum: evaluation points are x_i = A + i * dx
    for (long long i = 1; i <= iterations; ++i) {
        long double xi = a + (long double)i * dx;
        riemann_sum += (xi * xi);
    }
    
    // Multiply by the constant width of the rectangles
    riemann_sum *= dx;

    /**
     * Floating point comparison logic:
     * Due to precision limits of floating point numbers, we use a small epsilon (1e-9)
     * to check for equality.
     */
    long double diff = riemann_sum - c;
    long double epsilon = 1e-9;

    if (fabsl(diff) < epsilon) {
        cout << "Igual" << endl;
    } else if (riemann_sum > c) {
        cout << "Maior" << endl;
    } else {
        cout << "Menor" << endl;
    }

    return 0;
}