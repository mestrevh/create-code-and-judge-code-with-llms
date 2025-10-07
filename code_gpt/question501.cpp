/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string tipo;
    double valor, total = 0;
    int exames = 0, consultas = 0;

    for (int i = 0; i < 8; i++) {
        std::cin >> tipo >> valor;
        
        if (tipo == "exame") {
            exames++;
            if (exames > 2) {
                total += valor * 0.6;
            }
        } else if (tipo == "consulta") {
            consultas++;
            if (consultas > 3) {
                total += valor * 0.3;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}
