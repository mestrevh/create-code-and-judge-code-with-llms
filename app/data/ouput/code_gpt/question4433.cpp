/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iomanip>

struct Time {
    std::string nome;
    int pontos = 0, vitorias = 0, empates = 0, derrotas = 0;
    int gols_pro = 0, gols_contra = 0;

    int saldo_gols() const {
        return gols_pro - gols_contra;
    }
};

bool comparar(const Time &a, const Time &b) {
    if (a.pontos != b.pontos) return a.pontos > b.pontos;
    if (a.vitorias != b.vitorias) return a.vitorias > b.vitorias;
    if (a.saldo_gols() != b.saldo_gols()) return a.saldo_gols() > b.saldo_gols();
    if (a.gols_pro != b.gols_pro) return a.gols_pro > b.gols_pro;
    return a.nome < b.nome;
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    std::map<std::string, Time> times;

    for (int i = 0; i < N; ++i) {
        std::string entrada;
        std::getline(std::cin, entrada);
        std::istringstream iss(entrada);
        std::string time_casa, time_visitante;
        int gols_casa, gols_visitante;

        iss >> time_casa >> gols_casa;
        iss.ignore(3);
        iss >> gols_visitante >> time_visitante;

        times[time_casa].nome = time_casa;
        times[time_visitante].nome = time_visitante;

        times[time_casa].gols_pro += gols_casa;
        times[time_casa].gols_contra += gols_visitante;
        times[time_visitante].gols_pro += gols_visitante;
        times[time_visitante].gols_contra += gols_casa;

        if (gols_casa > gols_visitante) {
            times[time_casa].pontos += 3;
            times[time_casa].vitorias += 1;
            times[time_visitante].derrotas += 1;
        } else if (gols_casa < gols_visitante) {
            times[time_visitante].pontos += 3;
            times[time_visitante].vitorias += 1;
            times[time_casa].derrotas += 1;
        } else {
            times[time_casa].pontos += 1;
            times[time_visitante].pontos += 1;
            times[time_casa].empates += 1;
            times[time_visitante].empates += 1;
        }
    }

    std::vector<Time> tabela;
    for (const auto &p : times) {
        tabela.push_back(p.second);
    }

    std::sort(tabela.begin(), tabela.end(), comparar);

    for (size_t i = 0; i < tabela.size(); ++i) {
        const auto &t = tabela[i];
        std::cout << i + 1 << ". " << t.nome << " " << t.pontos << " "
                  << t.vitorias << " " << t.empates << " "
                  << t.derrotas << " " << t.gols_pro << " "
                  << t.gols_contra << " " << t.saldo_gols() << "\n";
    }

    return 0;
}
