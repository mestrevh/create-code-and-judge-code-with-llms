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
    
    double peso;
    while (cin >> peso) {
        double total = peso * 20.0;
        cout << "O valor do prato será: R$ " << fixed << setprecision(2) << total << "\n";
    }
    
    return 0;
}