/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    int N;
    double X;
    std::cin >> N >> X;

    if (N == 0) {
        std::cout << "Vamos pro posto Ipiranga ja!" << std::endl;
        return 0;
    }

    double total_distance = 0;
    for (int i = 0; i < 4; ++i) {
        std::string tourist_spot;
        int distance;
        std::cin >> tourist_spot >> distance;
        total_distance += distance;
    }

    double max_distance = N * X;

    if (max_distance >= total_distance) {
        std::cout << "Tokyo e demais, temos que vir de novo!" << std::endl;
    } else {
        std::cout << "Vamos de metro mesmo!" << std::endl;
    }

    return 0;
}
