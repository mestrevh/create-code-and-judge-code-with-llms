/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Competitor {
    double average;
    int periods;
};

bool compare(const Competitor &a, const Competitor &b) {
    if (a.average == b.average) return a.periods > b.periods;
    return a.average > b.average;
}

int main() {
    int V, p;
    std::cin >> V >> p;

    std::vector<double> celoGrades(p);
    for (int i = 0; i < p; i++) {
        std::cin >> celoGrades[i];
    }

    double celoAverage = std::accumulate(celoGrades.begin(), celoGrades.end(), 0.0) / p;

    int C;
    std::cin >> C;

    std::vector<Competitor> competitors(C);
    for (int i = 0; i < C; i++) {
        int cp;
        std::cin >> cp;
        competitors[i].periods = cp;
        competitors[i].average = 0.0;
        std::vector<double> compGrades(cp);
        for (int j = 0; j < cp; j++) {
            std::cin >> compGrades[j];
        }
        competitors[i].average = std::accumulate(compGrades.begin(), compGrades.end(), 0.0) / cp;
    }

    competitors.push_back({celoAverage, p});
    std::sort(competitors.begin(), competitors.end(), compare);

    int rank = std::find(competitors.begin(), competitors.end(), Competitor{celoAverage, p}) - competitors.begin() + 1;

    if (rank <= V) {
        std::cout << "Matriculado, seu ranking é " << rank << " dentre as " << V << " vagas" << std::endl;
    } else {
        std::cout << "Se não tivesse pago Dominó " << p << ", teria entrado..." << std::endl;
    }

    return 0;
}
