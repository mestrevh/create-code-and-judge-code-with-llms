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
    int n, l;
    while (std::cin >> n >> l && (n != 0 || l != 0)) {
        std::vector<int> a(l);
        for (int i = 0; i < l; ++i) {
            std::cin >> a[i];
        }

        int max_in_window = 0;
        int left = 0;
        for (int right = 0; right < l; ++right) {
            while (a[right] - a[left] >= n) {
                left++;
            }
            max_in_window = std::max(max_in_window, right - left + 1);
        }
        
        std::cout << n - max_in_window << std::endl;
    }
    return 0;
}
