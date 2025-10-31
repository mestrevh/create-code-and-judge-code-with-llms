/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double N;
    cin >> N;

    int value = static_cast<int>(N * 100 + 0.5);
    int notes[6] = {10000, 5000, 2000, 1000, 500, 200};
    int coins[6] = {100, 50, 25, 10, 5, 1};

    cout << fixed << setprecision(2);
    cout << "NOTAS:" << endl;

    for (int i = 0; i < 6; i++) {
        int count = value / notes[i];
        value %= notes[i];
        if (count > 0) {
            cout << count << " nota(s) de R$ " << notes[i] / 100.0 << endl;
        }
    }

    cout << "MOEDAS:" << endl;

    for (int i = 0; i < 6; i++) {
        int count = value / coins[i];
        value %= coins[i];
        if (count > 0) {
            cout << count << " moeda(s) de R$ " << coins[i] / 100.0 << endl;
        }
    }

    return 0;
}
