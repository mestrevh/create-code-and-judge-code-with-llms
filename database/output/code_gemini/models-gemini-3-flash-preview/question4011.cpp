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

    double a, b, c, n;
    while (cin >> a >> b >> c >> n) {
        cout << "Digite a quantidade de votos do candidato A:" << endl;
        cout << "Digite a quantidade de votos do candidato B:" << endl;
        cout << "Digite a quantidade de votos do candidato C:" << endl;
        cout << "Digite a quantidade de votos nulos:" << endl;

        double total = a + b + c + n;
        cout << fixed << setprecision(3);
        
        if (total == 0) {
            cout << "Candidato A: 0.000 %" << endl;
            cout << "Candidato B: 0.000 %" << endl;
            cout << "Candidato C: 0.000 %" << endl;
            cout << "Votos Nulos: 0.000 %" << endl;
        } else {
            cout << "Candidato A: " << (a * 100.0 / total) << " %" << endl;
            cout << "Candidato B: " << (b * 100.0 / total) << " %" << endl;
            cout << "Candidato C: " << (c * 100.0 / total) << " %" << endl;
            cout << "Votos Nulos: " << (n * 100.0 / total) << " %" << endl;
        }
    }

    return 0;
}