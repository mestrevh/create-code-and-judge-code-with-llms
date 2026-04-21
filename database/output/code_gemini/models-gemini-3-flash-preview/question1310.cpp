/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c, n;
    if (cin >> a >> b >> c >> n) {
        long long total = a + b + c + n;

        if (total == 0) {
            cout << "Candidato A: 0%\n";
            cout << "Candidato B: 0%\n";
            cout << "Candidato C: 0%\n";
            cout << "Nulos: 0%\n";
        } else {
            cout << "Candidato A: " << (a * 100) / total << "%\n";
            cout << "Candidato B: " << (b * 100) / total << "%\n";
            cout << "Candidato C: " << (c * 100) / total << "%\n";
            cout << "Nulos: " << (n * 100) / total << "%\n";
        }
    }

    return 0;
}