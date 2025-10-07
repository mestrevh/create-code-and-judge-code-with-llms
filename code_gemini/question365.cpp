/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t1, t2, t3, t4;
    std::cin >> t1 >> t2 >> t3 >> t4;
    int total = t1 + t2 + t3 + t4 - 3;
    std::cout << total << std::endl;
    return 0;
}
