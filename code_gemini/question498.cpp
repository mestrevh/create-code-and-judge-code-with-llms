/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int total_paginas_livro;
    std::cin >> total_paginas_livro;
    int pagina_anterior = 0;
    int pagina_atual;
    int maior_leitura_diaria = 0;
    for (int i = 0; i < 7; ++i) {
        std::cin >> pagina_atual;
        int paginas_lidas_hoje = pagina_atual - pagina_anterior;
        if (paginas_lidas_hoje > maior_leitura_diaria) {
            maior_leitura_diaria = paginas_lidas_hoje;
        }
        pagina_anterior = pagina_atual;
    }
    std::cout << pagina_anterior << std::endl;
    std::cout << maior_leitura_diaria << std::endl;
    return 0;
}
