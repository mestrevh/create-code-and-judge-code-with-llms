/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

struct Aluno {
    std::string nome;
    double media;
};

bool compararAlunos(const Aluno& a, const Aluno& b) {
    if (a.media < b.media) {
        return true;
    }
    if (a.media > b.media) {
        return false;
    }
    return a.nome < b.nome;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(); 

    std::vector<Aluno> alunos;

    for (int i = 0; i < n; ++i) {
        std::string linha;
        std::getline(std::cin, linha);
        std::stringstream ss(linha);

        std::string nome;
        std::getline(ss, nome, ',');

        std::vector<double> notas;
        std::string nota_str;
        while (std::getline(ss, nota_str, ',')) {
            try {
                notas.push_back(std::stod(nota_str));
            } catch (const std::invalid_argument& e) {
                // Handle empty string after comma if necessary
            }
        }

        while (notas.size() < 3) {
            notas.push_back(0.0);
        }

        std::vector<double> notas_para_media;
        notas_para_media.push_back(notas[0]);
        notas_para_media.push_back(notas[1]);
        notas_para_media.push_back(notas[2]);

        if (notas.size() == 4) {
            std::sort(notas_para_media.begin(), notas_para_media.end());
            if (notas[3] > notas_para_media[0]) {
                notas_para_media[0] = notas[3];
            }
        }

        double media_final = (notas_para_media[0] + notas_para_media[1] + notas_para_media[2]) / 3.0;
        
        alunos.push_back({nome, media_final});
    }

    std::sort(alunos.begin(), alunos.end(), compararAlunos);

    std::cout << std::fixed << std::setprecision(2);
    for (const auto& aluno : alunos) {
        std::cout << aluno.nome << " " << aluno.media << std::endl;
    }

    return 0;
}
