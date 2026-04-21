/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double somar(double a, double b) {
    return a + b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    if (!(cin >> a >> b)) return 0;

    double c = somar(a, b);

    cout << "O resultado de " << fixed << setprecision(1) << a << " + " << b << " eh ";
    
    if (c == floor(c)) {
        cout << (long long)c << endl;
    } else {
        cout << fixed << setprecision(1) << c << endl;
    }

    return 0;
}