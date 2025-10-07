/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int max_criancas;
    std::cin >> max_criancas;

    long long total_adultos = 0;
    long long total_criancas = 0;
    bool first_output = true;

    int adultos_grupo;
    int criancas_res_grupo;
    int convidados_grupo;

    while (std::cin >> adultos_grupo && adultos_grupo >= 0) {
        std::cin >> criancas_res_grupo >> convidados_grupo;

        if (!first_output) {
            std::cout << "***\n";
        }
        first_output = false;

        int criancas_total_grupo = criancas_res_grupo + convidados_grupo;
        long long futuro_total_criancas = total_criancas + criancas_total_grupo;

        if (futuro_total_criancas <= max_criancas) {
            std::cout << "Acesso permitido!\n";
            total_adultos += adultos_grupo;
            total_criancas += criancas_total_grupo;
        } else {
            if (convidados_grupo > 0) {
                std::cout << "Acesso permitido devido a presenca de convidado(s).\n";
                total_adultos += adultos_grupo;
                total_criancas += criancas_total_grupo;
            } else {
                std::cout << "Capacidade maxima de criancas atingida/excedida.\n";
                long long excesso = total_criancas - max_criancas;
                std::cout << "Tem " << excesso << " crianca(s) a mais que as " << max_criancas << " permitidas.\n";
            }
        }

        std::cout << "Adultos na piscina: " << total_adultos << "\n";
        std::cout << "Criancas na piscina: " << total_criancas << "\n";
    }

    return 0;
}
