/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double d;
    std::cin >> d;

    std::vector<double> custos(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> custos[i];
    }

    std::vector<double> eficiencias = {75.0, 50.0, 25.0, 50.0};
    std::vector<double> cb(4);
    double soma_cb = 0.0;

    for (int i = 0; i < 4; ++i) {
        if (custos[i] > 0) {
            cb[i] = eficiencias[i] / custos[i];
            soma_cb += cb[i];
        } else {
            cb[i] = 0; 
        }
    }

    double media_cb = soma_cb / 4.0;

    for (int i = 0; i < 4; ++i) {
        if (custos[i] > d) {
            std::cout << "foi de comes\n";
        } else {
            if (cb[i] < media_cb) {
                std::cout << "EH BOMBA TORRESMO\n";
            } else {
                std::cout << "eh dento\n";
            }
        }
    }

    return 0;
}
