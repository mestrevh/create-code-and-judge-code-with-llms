/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int A;
    std::cin >> A;
    int N;
    std::cin >> N;
    int visible_stars = 0;
    for (int i = 0; i < N; ++i) {
        int F;
        std::cin >> F;
        if (static_cast<long long>(A) * F >= 40000000) {
            visible_stars++;
        }
    }
    std::cout << visible_stars << std::endl;
    return 0;
}
