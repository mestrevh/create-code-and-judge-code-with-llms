/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main() {
    int dia_semana_num, opcao;
    double preco;

    std::cout << "Digite dia da semana: (1-SEG a 7-DOM)" << std::endl;
    std::cin >> dia_semana_num;

    std::cout << "Digite preco do produto em reais:" << std::endl;
    std::cin >> preco;

    std::cout << "Digite a opcao do produto: (2-prata 1-ouro)" << std::endl;
    std::cin >> opcao;

    double preco_final;

    if ((dia_semana_num >= 1 && dia_semana_num <= 3) && opcao == 1) {
        preco_final = preco / 2.0;
    } else if ((dia_semana_num == 4 || dia_semana_num == 5) && (preco >= 10.0 && preco <= 100.0)) {
        preco_final = preco / 3.0;
    } else if (dia_semana_num == 6 && opcao == 2) {
        preco_final = preco * 3.0;
    } else {
        preco_final = preco * 2.0;
    }

    std::vector<std::string> nomes_dias = {"", "seg", "ter", "qua", "qui", "sex", "sab", "dom"};
    std::string dia_str = "";
    if (dia_semana_num >= 1 && dia_semana_num <= 7) {
        dia_str = nomes_dias[dia_semana_num];
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "O preco do produto no dia " << dia_str << " e R$ " << preco_final << std::endl;

    return 0;
}
