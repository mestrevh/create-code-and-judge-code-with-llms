/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> sequence(100);
    
    cout << "Digite a sequencia de numero:\n";
    
    for (int i = 0; i < 100; ++i) {
        if (!(cin >> sequence[i])) break;
    }

    double target;
    if (cin >> target) {
        cout << "Indice no qual o numero desejado aparece:\n";
        for (int i = 0; i < 100; ++i) {
            if (sequence[i] == target) {
                cout << i << "\n";
            }
        }
    }

    return 0;
}