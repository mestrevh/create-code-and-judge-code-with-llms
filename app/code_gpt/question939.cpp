/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int number, count1 = 0, count2 = 0, count3 = 0, count4 = 0;

    while (true) {
        cout << "Digite um numero inteiro:\n";
        cin >> number;

        if (number < 0) break;

        if (number >= 0 && number <= 25) count1++;
        else if (number >= 26 && number <= 50) count2++;
        else if (number >= 51 && number <= 75) count3++;
        else if (number >= 76 && number <= 100) count4++;
    }

    cout << "Quantidade de numeros no intervalo 1: " << count1 << endl;
    cout << "Quantidade de numeros no intervalo 2: " << count2 << endl;
    cout << "Quantidade de numeros no intervalo 3: " << count3 << endl;
    cout << "Quantidade de numeros no intervalo 4: " << count4 << endl;

    return 0;
}
