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

    double a, b;
    if (!(cin >> a >> b)) return 0;

    cout << fixed << setprecision(1);
    
    // A + B = C
    cout << a << " + " << b << " = " << (a + b) << "\n";
    
    // B - A = D
    cout << b << " - " << a << " = " << (b - a) << "\n";
    
    // A * B = E
    cout << a << " * " << b << " = " << (a * b) << "\n";
    
    // B / A = F
    cout << b << " / " << a << " = ";
    if (a == 0) {
        cout << "Indeterminado" << "\n";
    } else {
        // Use defaultfloat to match the variable precision seen in test cases
        cout << defaultfloat << setprecision(17) << (b / a) << "\n";
    }

    return 0;
}