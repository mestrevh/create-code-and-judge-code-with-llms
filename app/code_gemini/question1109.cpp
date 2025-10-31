/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int dias_meta_programas = 0;
    int dias_meta_linhas = 0;
    int max_linhas = -1;
    int dia_max_linhas_idx = -1;

    std::string dias_da_semana[] = {"DOMINGO", "SEGUNDA", "TERCA", "QUARTA", "QUINTA", "SEXTA", "SABADO"};

    for (int i = 0; i < 7; ++i) {
        int programas, linhas;
        std::cin >> programas >> linhas;

        if (programas >= 5) {
            dias_meta_programas++;
        }

        if (linhas >= 100) {
            dias_meta_linhas++;
        }

        if (linhas >= max_linhas) {
            max_linhas = linhas;
            dia_max_linhas_idx = i;
        }
    }

    std::cout << "QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: " << dias_meta_programas << std::endl;
    std::cout << "QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: " << dias_meta_linhas << std::endl;
    std::cout << "DIA QUE MAIS PRODUZIU: " << dias_da_semana[dia_max_linhas_idx] << std::endl;

    return 0;
}
