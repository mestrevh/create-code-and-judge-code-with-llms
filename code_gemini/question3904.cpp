/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Presente {
    int id;
    int volume;
};

void resolver() {
    int n, k;
    std::cin >> n >> k;
    std::vector<Presente> presentes(n);
    for (int i = 0; i < n; ++i) {
        int h, w, l;
        std::cin >> presentes[i].id >> h >> w >> l;
        presentes[i].volume = h * w * l;
    }

    std::sort(presentes.begin(), presentes.end(), [](const Presente& a, const Presente& b) {
        if (a.volume != b.volume) {
            return a.volume > b.volume;
        }
        return a.id < b.id;
    });

    std::vector<int> ids_finais;
    ids_finais.reserve(k);
    for (int i = 0; i < k; ++i) {
        ids_finais.push_back(presentes[i].id);
    }

    std::sort(ids_finais.begin(), ids_finais.end());

    for (int i = 0; i < k; ++i) {
        std::cout << ids_finais[i] << (i == k - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        resolver();
    }
    return 0;
}
