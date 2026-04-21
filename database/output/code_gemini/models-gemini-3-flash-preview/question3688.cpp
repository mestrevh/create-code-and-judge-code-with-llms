/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int color;
    if (!(cin >> color)) return 0;

    string phrase;
    getline(cin >> ws, phrase);

    int n = phrase.length();
    if (n == 0) return 0;

    double base1, base2;
    if (color == 1) {
        base1 = 2.0;
        base2 = 6.0;
    } else {
        base1 = 4.0;
        base2 = 9.0;
    }

    double rate1, rate2;
    if (n <= 10) {
        rate1 = 0.75;
        rate2 = 0.25;
    } else if (n <= 30) {
        rate1 = 0.45;
        rate2 = 0.15;
    } else {
        rate1 = 0.20;
        rate2 = 0.10;
    }

    double total1 = base1 + (n * rate1);
    double total2 = base2 + (n * rate2);

    if (total1 <= total2) {
        cout << "A grafica 1 eh a mais em conta" << "\n";
        cout << "O preco sera: $" << fixed << setprecision(2) << total1 << endl;
    } else {
        cout << "A grafica 2 eh a mais em conta" << "\n";
        cout << "O preco sera: $" << fixed << setprecision(2) << total2 << endl;
    }

    return 0;
}