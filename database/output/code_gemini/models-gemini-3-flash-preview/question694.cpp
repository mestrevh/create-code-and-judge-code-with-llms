/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

/**
 * Function that returns the double of the maximum of two real numbers.
 * @param a First real number.
 * @param b Second real number.
 * @return 2.0 * max(a, b)
 */
double get_double_of_max(double a, double b) {
    return (a > b ? a : b) * 2.0;
}

int main() {
    // Optimize standard I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double num1, num2;
    
    // Read the two real numbers from standard input
    if (cin >> num1 >> num2) {
        // Calculate the result using the helper function
        double result = get_double_of_max(num1, num2);
        
        // Print the result formatted to 2 decimal places
        cout << fixed << setprecision(2) << result << "\n";
    }

    return 0;
}