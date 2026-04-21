/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double quantities[3][4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!(cin >> quantities[i][j])) break;
        }
    }

    double prices[4];
    for (int j = 0; j < 4; ++j) {
        if (!(cin >> prices[j])) break;
    }

    cout << "Digite a quantidade de ingredientes em cada produto (ovo, farinha, acucar e carne):" << "\n";
    cout << "Digite o preco de cada ingrediente (ovo, farinha, acucar e carne):" << "\n";

    string names[] = {"pastel", "empada", "kibe"};
    string articles[] = {"do", "da", "do"};

    for (int i = 0; i < 3; ++i) {
        double cost = 0;
        for (int j = 0; j < 4; ++j) {
            cost += quantities[i][j] * prices[j];
        }
        cout << "O custo " << articles[i] << " " << names[i] << " e R$ " << fixed << setprecision(2) << cost << "." << "\n";
    }

    return 0;
}

