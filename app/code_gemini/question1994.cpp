/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>

struct Aluno {
    std::string matricula_str;
    std::string primeiro_nome;
    std::string ultimo_nome;
    double media;
    int faltas;
    char status;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout << "VAZIO\n";
        return 0;
    }

    std::vector<Aluno> turma(n);
    double soma_medias = 0.0;
    int soma_faltas = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> turma[i].matricula_str
                 >> turma[i].primeiro_nome
                 >> turma[i].ultimo_nome
                 >> turma[i].media
                 >> turma[i].faltas
                 >> turma[i].status;
        soma_medias += turma[i].media;
        soma_faltas += turma[i].faltas;
    }

    double media_turma = soma_medias / n;
    double limite_faltas = 0.1 * soma_faltas;

    std::vector<std::pair<int, std::string>> destaques;

    for (int i = 0; i < n; ++i) {
        if (turma[i].media > media_turma &&
            turma[i].status == 'M' &&
            turma[i].faltas < limite_faltas) {
            destaques.push_back({i, turma[i].ultimo_nome});
        }
    }

    if (destaques.empty()) {
        std::cout << "VAZIO\n";
    } else {
        for (const auto& par : destaques) {
            std::cout << par.first << ":" << par.second << "\n";
        }
    }

    return 0;
}
