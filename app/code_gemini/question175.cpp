/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int L, D;
    std::cin >> L >> D;
    int K, P;
    std::cin >> K >> P;
    long long custo_km = (long long)L * K;
    long long numero_pedagios = L / D;
    long long custo_pedagios = numero_pedagios * P;
    long long custo_total = custo_km + custo_pedagios;
    std::cout << custo_total << std::endl;
    return 0;
}
