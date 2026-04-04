/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c, n;
    while (cout << "Digite a quantidade de votos do candidato A:" << endl && cin >> a) {
        cout << "Digite a quantidade de votos do candidato B:" << endl;
        if (!(cin >> b)) break;
        cout << "Digite a quantidade de votos do candidato C:" << endl;
        if (!(cin >> c)) break;
        cout << "Digite a quantidade de votos nulos:" << endl;
        if (!(cin >> n)) break;

        double total = a + b + c + n;
        if (total > 0) {
            cout << "Candidato A: " << (a * 100.0 / total) << " %" << endl;
            cout << "Candidato B: " << (b * 100.0 / total) << " %" << endl;
            cout << "Candidato C: " << (c * 100.0 / total) << " %" << endl;
            cout << "Votos Nulos: " << (n * 100.0 / total) << " %" << endl;
        }
    }

    return 0;
}