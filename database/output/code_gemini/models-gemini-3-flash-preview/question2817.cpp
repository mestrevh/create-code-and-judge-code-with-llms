/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numbers[3];
    if (!(cin >> numbers[0] >> numbers[1] >> numbers[2])) {
        return 0;
    }

    sort(numbers, numbers + 3);

    cout << "Digite cada numero e pressione ENTER:" << "\n";
    cout << "Numeros em ordem crescente:" << "\n";
    cout << numbers[0] << "\n";
    cout << numbers[1] << "\n";
    cout << numbers[2] << "\n";

    return 0;
}