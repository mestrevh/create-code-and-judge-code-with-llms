/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Função calcular_leds: recebe um caractere representando um dígito
 * e retorna o número de LEDs necessários para exibi-lo.
 */
int calcular_leds(char digit) {
    switch (digit) {
        case '1': return 2;
        case '2': return 5;
        case '3': return 5;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 3;
        case '8': return 7;
        case '9': return 6;
        case '0': return 6;
        default: return 0;
    }
}

int main() {
    // Otimização de I/O padrão Maratona de Programação
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        string v;
        cin >> v;

        long long total_leds = 0;
        for (char c : v) {
            total_leds += calcular_leds(c);
        }

        cout << total_leds << " leds" << "\n";
    }

    return 0;
}