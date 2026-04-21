/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Calculate values of f(x) = sin(x + 0.5) for x in [-5, 5] with a step of 0.5.
    // In Octave notation, x = -5:0.5:5 generates 21 points:
    // x = {-5.0, -4.5, -4.0, ..., 0.0, ..., 4.5, 5.0}
    // The problem asks for the values of f(x) in these points.
    vector<double> fx;
    for (int i = 0; i <= 20; ++i) {
        double x = -5.0 + i * 0.5;
        double val = sin(x + 0.5);
        // Standard sin(0) precision handling to ensure 0.00000 instead of -0.00000
        if (abs(val) < 1e-12) val = 0.0;
        fx.push_back(val);
    }

    // Replicate Octave's default vector output format.
    // The format groups values into columns for readability.
    cout << "fx =" << "\n\n";

    // First group: Columns 1 through 8 (Indices 0 to 7)
    cout << " Columns 1 through 8:" << "\n\n";
    for (int i = 0; i < 8; ++i) {
        cout << setw(10) << fixed << setprecision(5) << fx[i];
    }
    cout << "\n\n";

    // Second group: Columns 9 through 16 (Indices 8 to 15)
    cout << " Columns 9 through 16:" << "\n\n";
    for (int i = 8; i < 16; ++i) {
        cout << setw(10) << fixed << setprecision(5) << fx[i];
    }
    cout << "\n\n";

    // Third group: Columns 17 through 21 (Indices 16 to 20)
    cout << " Columns 17 through 21:" << "\n\n";
    for (int i = 16; i < 21; ++i) {
        cout << setw(10) << fixed << setprecision(5) << fx[i];
    }
    cout << "\n";

    return 0;
}