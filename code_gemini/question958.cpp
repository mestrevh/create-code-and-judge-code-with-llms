/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>

std::string formatar_dinheiro(double valor) {
    long long total_centavos = static_cast<long long>(std::round(valor * 100.0));

    long long reais = total_centavos / 100;
    int centavos = total_centavos % 100;

    std::string parte_inteira_str = std::to_string(reais);
    std::string parte_inteira_formatada;

    int count = 0;
    for (int i = parte_inteira_str.length() - 1; i >= 0; --i) {
        if (count > 0 && count % 3 == 0) {
            parte_inteira_formatada += '.';
        }
        parte_inteira_formatada += parte_inteira_str[i];
        count++;
    }
    std::reverse(parte_inteira_formatada.begin(), parte_inteira_formatada.end());

    std::stringstream ss_centavos;
    ss_centavos << std::setw(2) << std::setfill('0') << centavos;
    std::string parte_decimal_formatada = ss_centavos.str();

    return "R$ " + parte_inteira_formatada + "," + parte_decimal_formatada;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double valor;
    std::cin >> valor;
    std::cout << formatar_dinheiro(valor) << std::endl;

    return 0;
}
