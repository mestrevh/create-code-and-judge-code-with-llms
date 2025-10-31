/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    long long t1 = 0, t2 = 1;
    if (n >= 1) {
        std::cout << t1 << "\n";
    }
    if (n >= 2) {
        std::cout << t2 << "\n";
    }
    for (int i = 2; i < n; ++i) {
        long long nextTerm = t1 + t2;
        std::cout << nextTerm << "\n";
        t1 = t2;
        t2 = nextTerm;
    }
    return 0;
}
