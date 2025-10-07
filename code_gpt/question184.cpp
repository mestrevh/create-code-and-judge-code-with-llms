/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    int N, A, L, P;
    std::cin >> N >> A >> L >> P;
    int diametro = N;
    int raio = diametro / 2;
    
    if (A >= diametro && L >= diametro && P >= diametro) {
        std::cout << 'S' << std::endl;
    } else {
        std::cout << 'N' << std::endl;
    }
    
    return 0;
}
