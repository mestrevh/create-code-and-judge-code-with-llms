/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Country {
    int id, gold, silver, bronze;

    bool operator<(const Country &other) const {
        if (gold != other.gold) return gold > other.gold;
        if (silver != other.silver) return silver > other.silver;
        if (bronze != other.bronze) return bronze > other.bronze;
        return id < other.id;
    }
};

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<Country> countries(N);

    for (int i = 0; i < N; ++i) {
        countries[i] = {i + 1, 0, 0, 0};
    }

    for (int i = 0; i < M; ++i) {
        int O, P, B;
        std::cin >> O >> P >> B;
        countries[O - 1].gold++;
        countries[P - 1].silver++;
        countries[B - 1].bronze++;
    }

    std::sort(countries.begin(), countries.end());

    for (const auto &country : countries) {
        std::cout << country.id << std::endl;
    }

    return 0;
}
