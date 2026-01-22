/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int calcular_leds(char digito) {
    switch (digito) {
        case '0': return 6;
        case '1': return 2;
        case '2': return 5;
        case '3': return 5;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 3;
        case '8': return 7;
        case '9': return 6;
        default: return 0;
    }
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string valor;
        getline(cin, valor);
        int total_leds = 0;
        for (char digito : valor) {
            total_leds += calcular_leds(digito);
        }
        cout << total_leds << " leds" << endl;
    }
    return 0;
}
