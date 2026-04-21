/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long p;
    double c;

    if (cin >> p >> c) {
        if (c == 0) return 0;
        
        long long total = (long long)round(p * 100.0 / c);
        long long remaining = total - p;

        cout << "O documento possui " << total << " paginas" << "\n";
        cout << "Já foram impressas " << p << " paginas" << "\n";
        cout << "Faltam " << remaining << " paginas" << "\n";
    }

    return 0;
}