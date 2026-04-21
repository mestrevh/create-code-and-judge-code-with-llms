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

    double total = 0.0;
    double current;
    int count = 0;

    cout << "Insira os valores das doacoes:" << endl;

    while (cin >> current && current >= 0) {
        total += current;
        count++;
    }

    double average = 0.0;
    if (count > 0) {
        average = total / count;
    }

    cout << fixed << setprecision(2);
    cout << "Total arrecadado: " << total << endl;
    cout << "Valor medio da doacao: " << average << endl;

    return 0;
}