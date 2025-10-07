/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    double total_receber = 0.0;
    int cont_radio = 0;
    int cont_tv = 0;
    int cont_revista = 0;
    int cont_outdoor = 0;
    std::string tipo_midia;
    std::string faixa_radio;
    int horario_tv;

    for (int i = 0; i < 7; ++i) {
        std::cin >> tipo_midia;

        if (tipo_midia == "Rádio") {
            cont_radio++;
            std::cin >> faixa_radio;
            if (faixa_radio == "FM") {
                total_receber += 500;
            } else {
                total_receber += 300;
            }
        } else if (tipo_midia == "TV") {
            cont_tv++;
            std::cin >> horario_tv;
            if (horario_tv > 20) {
                total_receber += 2000;
            } else {
                total_receber += 1200;
            }
        } else if (tipo_midia == "Revista") {
            cont_revista++;
            total_receber += 750;
        } else if (tipo_midia == "Outdoor") {
            cont_outdoor++;
            total_receber += 1500;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << total_receber << std::endl;
    std::cout << cont_radio << std::endl;
    std::cout << cont_tv << std::endl;
    std::cout << cont_revista << std::endl;
    std::cout << cont_outdoor << std::endl;

    return 0;
}
