/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Digite os 10 numeros inteiros:" << endl;
    
    vector<int> numbers(10);
    for (int i = 0; i < 10; ++i) {
        if (!(cin >> numbers[i])) break;
    }

    cout << "Numeros pares na ordem inversa:" << endl;

    bool first = true;
    for (int i = 9; i >= 0; --i) {
        if (numbers[i] % 2 == 0) {
            if (!first) {
                cout << " ";
            }
            cout << numbers[i];
            first = false;
        }
    }
    cout << endl;

    return 0;
}