/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n1, n2, n3, f;
    if (!(cin >> n1 >> n2 >> n3 >> f)) return 0;

    double average = (n1 * 2.0 + n2 * 2.0 + n3 * 3.0) / 7.0;
    double rounded_avg = std::round(average * 10.0) / 10.0;
    int frequency_pct = (int)std::round(f * 100.0);

    cout << "Frequencia: " << frequency_pct << "%" << endl;
    cout << "Media: " << fixed << setprecision(1) << rounded_avg << endl;

    if (frequency_pct < 75) {
        cout << "Aluno reprovado por faltas!" << endl;
    } else {
        if (rounded_avg > 9.0) {
            cout << "Aluno aprovado com louvor!" << endl;
        } else if (rounded_avg >= 6.0) {
            cout << "Aluno aprovado!" << endl;
        } else if (rounded_avg >= 4.0) {
            cout << "Aluno de rec!" << endl;
        } else {
            cout << "Aluno reprovado!" << endl;
        }
    }

    return 0;
}