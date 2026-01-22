/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int minutos_por_processo;
    std::cin >> minutos_por_processo;
    int total_minutos_dia = 8 * 60;
    int total_processos = total_minutos_dia / minutos_por_processo;
    std::cout << total_processos << std::endl;
    return 0;
}
