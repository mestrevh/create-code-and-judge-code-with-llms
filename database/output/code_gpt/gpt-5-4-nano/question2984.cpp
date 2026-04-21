/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double n1, n2, n3, freq;
    if (!(cin >> n1 >> n2 >> n3 >> freq)) return 0;

    double media = (n1 * 2.0 + n2 * 2.0 + n3 * 3.0) / 7.0;
    double mediaArred = round(media * 10.0) / 10.0;

    cout << "Frequencia: " << fixed << setprecision(0) << (freq * 100.0) << "%\n";
    cout << "Media: " << fixed << setprecision(1) << mediaArred << "\n";

    if (freq < 0.75) {
        cout << "Aluno reprovado por faltas!";
    } else {
        if (mediaArred > 9.0) {
            cout << "Aluno aprovado com louvor!";
        } else if (mediaArred >= 6.0) {
            cout << "Aluno aprovado!";
        } else if (mediaArred >= 4.0) {
            cout << "Aluno de rec!";
        } else {
            cout << "Aluno reprovado!";
        }
    }

    return 0;
}