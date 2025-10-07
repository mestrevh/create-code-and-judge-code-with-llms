/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> d[i];
    }

    int q;
    std::cin >> q;

    while (q--) {
        int x;
        std::cin >> x;

        auto it_lo = std::lower_bound(d.begin(), d.end(), x);
        int lo = it_lo - d.begin();

        auto it_hi = std::upper_bound(d.begin(), d.end(), x);
        int hi = (it_hi - d.begin()) - 1;

        std::cout << lo << " " << hi << "\n";
    }

    return 0;
}
