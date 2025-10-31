/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, p;
    std::cin >> n >> p;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (x > 0 && y > 0 && (x + y) >= p) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
