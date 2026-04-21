/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::vector<int> h;
    h.reserve(10000);

    while (std::cin >> n && n != 0) {
        h.resize(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> h[i];
        }

        int peaks = 0;
        for (int i = 0; i < n; ++i) {
            int current = h[i];
            int prev = (i == 0) ? h[n - 1] : h[i - 1];
            int next = (i == n - 1) ? h[0] : h[i + 1];

            if ((current > prev && current > next) || (current < prev && current < next)) {
                peaks++;
            }
        }
        std::cout << peaks << "\n";
    }

    return 0;
}