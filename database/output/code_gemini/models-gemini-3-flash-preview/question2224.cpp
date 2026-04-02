/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a[3];
    while (std::cin >> a[0] >> a[1] >> a[2]) {
        std::sort(a, a + 3, std::greater<long long>());
        std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    }

    return 0;
}