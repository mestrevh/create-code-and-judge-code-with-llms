/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    double x;
    std::cin >> n >> x;

    if (n == 0) {
        std::cout << "Vamos pro posto Ipiranga ja!" << std::endl;
        return 0;
    }

    int total_distancia = 0;
    for (int i = 0; i < 4; ++i) {
        std::string s;
        int d;
        std::cin >> s >> d;
        total_distancia += d;
    }

    double autonomia_total = n * x;

    if (autonomia_total >= total_distancia) {
        std::cout << "Tokyo e demais, temos que vir de novo!" << std::endl;
    } else {
        std::cout << "Vamos de metro mesmo!" << std::endl;
    }

    return 0;
}
