/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int budget, totalCost = 0, value;
    string productName;

    cin >> budget;

    for (int i = 0; i < 6; i++) {
        cin >> value >> productName;
        totalCost += value;
    }

    if (totalCost <= budget) {
        cout << "Mario gastara um total de R$ " << totalCost << "." << endl;
    } else {
        cout << "Infelizmente nao sera possivel comprar tudo, faltam R$ " << totalCost - budget << "." << endl;
    }

    return 0;
}
