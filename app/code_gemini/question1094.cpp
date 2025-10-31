/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long total_A = 0;
    long long total_B = 0;
    long long total_C = 0;
    long long total_brancos = 0;
    long long total_nulos = 0;

    int secao;
    while (std::cin >> secao && secao != 0) {
        int votos_A, votos_B, votos_C, votos_brancos, votos_nulos;
        std::cin >> votos_A >> votos_B >> votos_C >> votos_brancos >> votos_nulos;
        total_A += votos_A;
        total_B += votos_B;
        total_C += votos_C;
        total_brancos += votos_brancos;
        total_nulos += votos_nulos;
    }

    long long total_votantes = total_A + total_B + total_C + total_brancos + total_nulos;
    long long total_validos = total_A + total_B + total_C;

    std::string vencedor = "";
    if (total_validos > 0) {
        long long max_votos = std::max({total_A, total_B, total_C});
        int num_vencedores = 0;
        if (total_A == max_votos) num_vencedores++;
        if (total_B == max_votos) num_vencedores++;
        if (total_C == max_votos) num_vencedores++;

        if (num_vencedores == 1) {
            if (total_A == max_votos) {
                vencedor = "A";
            } else if (total_B == max_votos) {
                vencedor = "B";
            } else {
                vencedor = "C";
            }
        }
    }
    
    bool eleicao_valida = (total_brancos + total_nulos) < total_validos;

    bool segundo_turno = false;
    if (eleicao_valida) {
        if (total_validos > 0) {
            if (!vencedor.empty()) {
                long long max_votos = std::max({total_A, total_B, total_C});
                if (max_votos * 2 <= total_validos) {
                    segundo_turno = true;
                }
            } else {
                segundo_turno = true;
            }
        }
    }

    std::cout << "Numero de votantes: " << total_votantes << "\n";
    std::cout << "Total A: " << total_A << "\n";
    std::cout << "Total B: " << total_B << "\n";
    std::cout << "Total C: " << total_C << "\n";
    std::cout << "Brancos: " << total_brancos << "\n";
    std::cout << "Nulos: " << total_nulos << "\n";
    std::cout << "Validos: " << total_validos << "\n";
    std::cout << "Candidato mais votado: " << vencedor << "\n";
    std::cout << "Eleicao valida? " << (eleicao_valida ? "True" : "False") << "\n";
    std::cout << "Segundo turno? " << (segundo_turno ? "True" : "False") << "\n";

    return 0;
}
