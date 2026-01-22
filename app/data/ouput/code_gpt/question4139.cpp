/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    std::string horaInicial;
    int minutosParaAdicionar;

    std::getline(std::cin, horaInicial);
    std::cin >> minutosParaAdicionar;

    int horas, minutos;
    char ignorar;

    std::istringstream(horaInicial) >> horas >> ignorar >> minutos;

    minutos += minutosParaAdicionar;
    horas += minutos / 60;
    minutos %= 60;
    horas %= 24;

    std::cout << std::setw(2) << std::setfill('0') << horas << ":"
              << std::setw(2) << std::setfill('0') << minutos << std::endl;

    return 0;
}
