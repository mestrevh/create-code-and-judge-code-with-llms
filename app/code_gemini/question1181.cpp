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

    int febre_count = 0;
    int temp_normal_count = 0;
    int otima_count = 0;
    int normal_count = 0;
    int limitrofe_count = 0;
    int hipertensao_count = 0;
    int sistolica_count = 0;
    int observacao_count = 0;

    for (int i = 0; i < n; ++i) {
        int temp, ps, pd;
        std::cin >> temp >> ps >> pd;

        if (temp > 38) {
            febre_count++;
        } else {
            temp_normal_count++;
        }

        if (ps >= 140 && pd < 90) {
            sistolica_count++;
        } else if (ps < 140 && pd >= 90) {
            observacao_count++;
        } else if (ps >= 140 && pd >= 90) {
            hipertensao_count++;
        } else if ((ps >= 130 && ps <= 139) || (pd >= 85 && pd <= 89)) {
            limitrofe_count++;
        } else if (ps < 120 && pd < 80) {
            otima_count++;
        } else if (ps < 130 && pd < 85) {
            normal_count++;
        }
    }

    std::cout << "febre: " << febre_count << "\n";
    std::cout << "temperatura normal: " << temp_normal_count << "\n";
    std::cout << "pressao otima: " << otima_count << "\n";
    std::cout << "pressao normal: " << normal_count << "\n";
    std::cout << "pressao limitrofe: " << limitrofe_count << "\n";
    std::cout << "hipertensao: " << hipertensao_count << "\n";
    std::cout << "pressao sistolica: " << sistolica_count << "\n";
    std::cout << "observacao: " << observacao_count << "\n";

    return 0;
}
