/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> cpfs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cpfs[i];
    }

    std::vector<int> notas(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> notas[i];
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        long long cpf_query;
        std::cin >> cpf_query;

        auto it = std::lower_bound(cpfs.begin(), cpfs.end(), cpf_query);

        if (it != cpfs.end() && *it == cpf_query) {
            int index = std::distance(cpfs.begin(), it);
            std::cout << notas[index] << "\n";
        } else {
            std::cout << "NAO SE APRESENTOU\n";
        }
    }

    return 0;
}
