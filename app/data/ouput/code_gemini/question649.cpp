/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <ext/rope>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    while (std::cin >> N >> M && (N != 0 || M != 0)) {
        std::vector<int> X(M);
        for (int i = 0; i < M; ++i) {
            std::cin >> X[i];
        }

        __gnu_cxx::rope<int> r;
        for (int i = M + 1; i <= N; ++i) {
            r.push_back(i);
        }

        for (int i = M; i >= 1; --i) {
            r.insert(X[i - 1], i);
        }

        if (!r.empty()) {
            __gnu_cxx::rope<int>::iterator it = r.begin();
            std::cout << *it;
            ++it;
            for (; it != r.end(); ++it) {
                std::cout << " " << *it;
            }
        }
        std::cout << "\n";
    }

    return 0;
}
