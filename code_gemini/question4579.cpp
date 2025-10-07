/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Sala {
    int id;
    int approved_count;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Sala> salas;
    salas.reserve(n);

    for (int i = 0; i < n; ++i) {
        int id, q;
        std::cin >> id >> q;

        int current_approved_count = 0;
        for (int j = 0; j < q; ++j) {
            std::string nome;
            double presence;
            std::cin >> nome >> presence;

            int n1, n2, n3;

            std::cin >> n1 >> n2 >> n3;
            double math_avg = (n1 + n2 + n3) / 3.0;

            std::cin >> n1 >> n2 >> n3;
            double port_avg = (n1 + n2 + n3) / 3.0;

            std::cin >> n1 >> n2 >> n3;
            double hist_avg = (n1 + n2 + n3) / 3.0;

            if (presence >= 0.75 && math_avg >= 7.0 && port_avg >= 7.0 && hist_avg >= 7.0) {
                current_approved_count++;
            }
        }
        salas.push_back({id, current_approved_count});
    }

    std::stable_sort(salas.begin(), salas.end(), [](const Sala& a, const Sala& b) {
        return a.approved_count > b.approved_count;
    });

    for (size_t i = 0; i < salas.size(); ++i) {
        std::cout << i + 1 << ". [SALA #" << salas[i].id << "] APROVADOS: " << salas[i].approved_count << "\n";
    }

    return 0;
}
