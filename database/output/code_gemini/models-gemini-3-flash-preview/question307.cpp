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

    double N;
    if (!(cin >> N)) return 0;

    long long cents = (long long)round(N * 100.0);

    int notes[] = {10000, 5000, 2000, 1000, 500, 200};
    const char* notes_labels[] = {"100.00", "50.00", "20.00", "10.00", "5.00", "2.00"};
    
    cout << "NOTAS:" << "\n";
    for (int i = 0; i < 6; ++i) {
        int count = cents / notes[i];
        cents %= notes[i];
        cout << count << " nota(s) de R$ " << notes_labels[i] << "\n";
    }

    int coins[] = {100, 50, 25, 10, 5, 1};
    const char* coins_labels[] = {"1.00", "0.50", "0.25", "0.10", "0.05", "0.01"};

    cout << "MOEDAS:" << "\n";
    for (int i = 0; i < 6; ++i) {
        int count = cents / coins[i];
        cents %= coins[i];
        cout << count << " moeda(s) de R$ " << coins_labels[i] << "\n";
    }

    return 0;
}