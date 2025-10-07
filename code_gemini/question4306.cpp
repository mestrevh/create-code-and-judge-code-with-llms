/*
Código criado pelo Gemini Pro 1.5
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

    double efficiencies[4] = {75.0, 50.0, 25.0, 50.0};
    double costs[4];
    std::cin >> costs[0] >> costs[1] >> costs[2] >> costs[3];

    double cb[4];
    double sum_cb = 0.0;

    for (int i = 0; i < 4; ++i) {
        cb[i] = efficiencies[i] / costs[i];
        sum_cb += cb[i];
    }

    double avg_cb = sum_cb / 4.0;

    for (int i = 0; i < 4; ++i) {
        if (d < costs[i]) {
            std::cout << "foi de comes\n";
        } else {
            if (cb[i] < avg_cb) {
                std::cout << "EH BOMBA TORRESMO\n";
            } else {
                std::cout << "eh dento\n";
            }
        }
    }

    return 0;
}
