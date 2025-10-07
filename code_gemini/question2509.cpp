/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int calcular_leds(char digito) {
    switch (digito) {
        case '0':
            return 6;
        case '1':
            return 2;
        case '2':
            return 5;
        case '3':
            return 5;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 3;
        case '8':
            return 7;
        case '9':
            return 6;
        default:
            return 0;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    while (N--) {
        std::string V;
        std::cin >> V;
        long long total_leds = 0;
        for (char c : V) {
            total_leds += calcular_leds(c);
        }
        std::cout << total_leds << " leds\n";
    }
    return 0;
}
