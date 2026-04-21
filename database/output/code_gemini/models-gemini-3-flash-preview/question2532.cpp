/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    while (cin >> a >> b) {
        cout << "Digite o valor de A:\n";
        cout << "Digite o valor de B:\n";
        
        double result = (a > b) ? a : b;
        
        cout << "O maior valor digitado foi: " << result << "\n";
    }

    return 0;
}