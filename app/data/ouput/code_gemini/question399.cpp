/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

double CalculaHospedagem(std::string tipo, int dias) {
    double valor_diaria = 0.0;

    if (tipo == "individual") {
        valor_diaria = 125.0;
    } else if (tipo == "dupla") {
        valor_diaria = 140.0;
    } else if (tipo == "tripla") {
        valor_diaria = 180.0;
    }

    double total = valor_diaria * dias;

    if (dias >= 3) {
        total *= 0.85;
    }

    return total;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string tipo_apartamento;
    int quantidade_dias;

    std::cin >> tipo_apartamento;
    std::cin >> quantidade_dias;

    double valor_a_pagar = CalculaHospedagem(tipo_apartamento, quantidade_dias);

    std::cout << std::fixed << std::setprecision(2) << valor_a_pagar << std::endl;

    return 0;
}
