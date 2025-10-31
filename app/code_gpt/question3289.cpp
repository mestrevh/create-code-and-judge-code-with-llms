/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>

void converteHora(int h, int m) {
    if (h == -1) return;
    std::string periodo = (h >= 12) ? "P.M" : "A.M";
    if (h == 0) h = 12;
    else if (h > 12) h -= 12;
    std::cout << h << ":" << (m < 10 ? "0" : "") << m << " " << periodo << std::endl;
}

int main() {
    std::string entrada;
    while (std::getline(std::cin, entrada)) {
        if (entrada == "-1:00") break;
        int h, m;
        char ignorar;
        std::stringstream ss(entrada);
        ss >> h >> ignorar >> m;
        converteHora(h, m);
    }
    return 0;
}
