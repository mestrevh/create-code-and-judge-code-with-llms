/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    int interval1 = 0, interval2 = 0, interval3 = 0, interval4 = 0;

    while (true) {
        cout << "Digite um numero inteiro:\n";
        if (!(cin >> num) || num < 0) {
            break;
        }

        if (num >= 0 && num <= 25) {
            interval1++;
        } else if (num >= 26 && num <= 50) {
            interval2++;
        } else if (num >= 51 && num <= 75) {
            interval3++;
        } else if (num >= 76 && num <= 100) {
            interval4++;
        }
    }

    cout << "Quantidade de numeros no intervalo 1: " << interval1 << "\n";
    cout << "Quantidade de numeros no intervalo 2: " << interval2 << "\n";
    cout << "Quantidade de numeros no intervalo 3: " << interval3 << "\n";
    cout << "Quantidade de numeros no intervalo 4: " << interval4 << "\n";

    return 0;
}