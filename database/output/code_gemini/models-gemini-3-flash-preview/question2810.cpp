/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    // Optimize standard I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read the integer value N
    if (cin >> n) {
        // Output the prompt as requested in the test cases and description
        cout << "Digite o valor inteiro:" << "\n";

        // Greedy decomposition using standard Brazilian banknotes and coins
        // Banknote: 100
        cout << n / 100 << " nota(s) de R$ 100,00" << "\n";
        n %= 100;

        // Banknote: 50
        cout << n / 50 << " nota(s) de R$ 50,00" << "\n";
        n %= 50;

        // Banknote: 20
        cout << n / 20 << " nota(s) de R$ 20,00" << "\n";
        n %= 20;

        // Banknote: 10
        cout << n / 10 << " nota(s) de R$ 10,00" << "\n";
        n %= 10;

        // Banknote: 5
        cout << n / 5 << " nota(s) de R$ 5,00" << "\n";
        n %= 5;

        // Banknote: 2
        cout << n / 2 << " nota(s) de R$ 2,00" << "\n";
        n %= 2;

        // Coin: 1 (Note the change from "nota(s)" to "moeda(s)" for R$ 1,00)
        cout << n << " moeda(s) de R$ 1,00" << endl;
    }

    return 0;
}