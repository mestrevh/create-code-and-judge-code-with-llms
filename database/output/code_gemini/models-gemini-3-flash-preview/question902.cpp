/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long base, expoente;
    while (cin >> base >> expoente) {
        cout << "Informe a base:\n";
        cout << "Informe o expoente:\n";
        
        long long resultado = 1;
        if (expoente < 0) {
            // Negative exponents are generally not handled in basic repetition/accumulator problems
            // but for completeness in an integer context, we result in 0 or 1 based on base.
            // Standard competitive programming integer power for negative exponent is 0.
            resultado = 0; 
        } else {
            for (long long i = 0; i < expoente; ++i) {
                resultado *= base;
            }
        }
        
        cout << "Resultado: " << resultado << "\n";
    }

    return 0;
}