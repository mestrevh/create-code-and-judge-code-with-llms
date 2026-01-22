/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Presente {
    int id;
    int volume;
};

bool comparar(const Presente &a, const Presente &b) {
    if (a.volume != b.volume) 
        return a.volume > b.volume;
    return a.id < b.id;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N, K;
        std::cin >> N >> K;
        std::vector<Presente> presentes(N);
        for (int i = 0; i < N; ++i) {
            int id, h, w, l;
            std::cin >> id >> h >> w >> l;
            presentes[i] = {id, h * w * l};
        }
        std::sort(presentes.begin(), presentes.end(), comparar);
        
        std::vector<int> ids;
        for (int i = 0; i < K; ++i)
            ids.push_back(presentes[i].id);
        
        std::sort(ids.begin(), ids.end());
        for (int i = 0; i < K; ++i) {
            if (i > 0) std::cout << " ";
            std::cout << ids[i];
        }
        std::cout << "\n";
    }
    return 0;
}
