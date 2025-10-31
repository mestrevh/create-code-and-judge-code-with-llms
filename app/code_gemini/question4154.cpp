/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, c, m;
    std::cin >> a >> c >> m;

    int num_adultos = a / m;
    int num_criancas = c / m;
    
    int num_adultos_mais_um = 0;
    int num_criancas_mais_um = 0;
    int num_mistas = 0;

    int sobra_adultos = a % m;
    int sobra_criancas = c % m;

    int custo_mistas = 0;

    if ((sobra_adultos > 0 || sobra_criancas > 0) && (sobra_adultos + sobra_criancas == m)) {
        num_mistas = 1;
        custo_mistas = 2 * m;
        sobra_adultos = 0;
        sobra_criancas = 0;
    } else if (sobra_adultos > 0 && sobra_criancas > 0 && sobra_adultos % 2 == 0 && sobra_criancas % 2 == 0) {
        if (sobra_adultos + sobra_criancas > m) {
            num_mistas = 2;
            custo_mistas = 4 * m;
        } else {
            num_mistas = 1;
            custo_mistas = 2 * (sobra_adultos + sobra_criancas);
        }
        sobra_adultos = 0;
        sobra_criancas = 0;
    }
    
    if (sobra_adultos > 0) {
        if (sobra_adultos < 4) {
            num_adultos_mais_um = sobra_adultos;
            num_adultos -= sobra_adultos;
        } else {
            num_adultos++;
        }
    }

    if (sobra_criancas > 0) {
        if (sobra_criancas < 4) {
            num_criancas_mais_um = sobra_criancas;
            num_criancas -= sobra_criancas;
        } else {
            num_criancas++;
        }
    }
    
    if (num_adultos > 0) {
        printf("%d mesas com adultos: R$%d\n", num_adultos, num_adultos * 3 * m);
    }
    if (num_adultos_mais_um > 0) {
        printf("%d mesas com adultos+1: R$%d\n", num_adultos_mais_um, num_adultos_mais_um * 4 * (m + 1));
    }
    if (num_criancas > 0) {
        printf("%d mesas com criancas: R$%d\n", num_criancas, num_criancas * 2 * m);
    }
    if (num_criancas_mais_um > 0) {
        printf("%d mesas com criancas+1: R$%d\n", num_criancas_mais_um, num_criancas_mais_um * 3 * (m + 1));
    }
    if (num_mistas > 0) {
        printf("%d mesas mistas: R$%d\n", num_mistas, custo_mistas);
    }

    return 0;
}
