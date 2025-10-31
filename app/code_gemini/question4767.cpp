/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double hora_saida_float, tempo_trajeto;
    int vagas_atuais;
    std::cin >> hora_saida_float >> tempo_trajeto >> vagas_atuais;

    double hora_chegada_float = hora_saida_float + tempo_trajeto / 60.0;

    if (hora_saida_float < 8.0 || hora_saida_float > 20.0 || hora_chegada_float > 20.0) {
        std::cout << "ulaM esta dormindo\n";
        return 0;
    }

    double inicio_trajeto_min = hora_saida_float * 60.0;
    double fim_trajeto_min = inicio_trajeto_min + tempo_trajeto;

    int vagas_perdidas = 0;

    double inicio_int1 = 480.0;
    double fim_int1 = 720.0;
    double tempo_no_int1 = std::max(0.0, std::min(fim_trajeto_min, fim_int1) - std::max(inicio_trajeto_min, inicio_int1));
    vagas_perdidas += static_cast<int>(std::floor(tempo_no_int1 / 5.0));

    double inicio_int2 = 720.0;
    double fim_int2 = 960.0;
    double tempo_no_int2 = std::max(0.0, std::min(fim_trajeto_min, fim_int2) - std::max(inicio_trajeto_min, inicio_int2));
    vagas_perdidas += static_cast<int>(std::floor(tempo_no_int2 / 4.0));

    double inicio_int3 = 960.0;
    double fim_int3 = 1200.0;
    double tempo_no_int3 = std::max(0.0, std::min(fim_trajeto_min, fim_int3) - std::max(inicio_trajeto_min, inicio_int3));
    vagas_perdidas += static_cast<int>(std::floor(tempo_no_int3 / 2.0));

    int vagas_restantes = vagas_atuais - vagas_perdidas;

    if (vagas_restantes >= 1) {
        std::cout << "possui vaga para olecraM\n";
    } else {
        std::cout << "nao tera vaga\n";
    }

    return 0;
}
