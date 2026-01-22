/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> parent;
std::vector<int> sz;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            std::swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);

        for (int i = 0; i < m; ++i) {
            int k;
            std::cin >> k;
            if (k > 0) {
                int first_student;
                std::cin >> first_student;
                for (int j = 1; j < k; ++j) {
                    int other_student;
                    std::cin >> other_student;
                    unite_sets(first_student, other_student);
                }
            }
        }

        std::cout << sz[find_set(0)] << "\n";
    }

    return 0;
}
