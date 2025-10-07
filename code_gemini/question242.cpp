/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <list>

void solve() {
    int m, c;
    std::cin >> m >> c;
    std::vector<std::list<int>> hash_table(m);
    for (int i = 0; i < c; ++i) {
        int key;
        std::cin >> key;
        int index = key % m;
        hash_table[index].push_back(key);
    }

    for (int i = 0; i < m; ++i) {
        std::cout << i << " -> ";
        for (int key : hash_table[i]) {
            std::cout << key << " -> ";
        }
        std::cout << "\\" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            std::cout << std::endl;
        }
        solve();
    }
    return 0;
}
