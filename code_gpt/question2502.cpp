/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Consulta {
    int inicio;
    int fim;
};

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<Consulta> agendadas(N);
    for (int i = 0; i < N; ++i) {
        cin >> agendadas[i].inicio >> agendadas[i].fim;
    }

    vector<int> desagendadas(M);
    for (int i = 0; i < M; ++i) {
        cin >> desagendadas[i];
    }

    sort(agendadas.begin(), agendadas.end(), [](const Consulta &a, const Consulta &b) {
        return a.fim < b.fim;
    });
    sort(desagendadas.begin(), desagendadas.end());

    int tempoAtual = 0;
    int atendidos = 0;

    for (const auto &consulta : agendadas) {
        tempoAtual = max(tempoAtual, consulta.inicio);
        for (int j = 0; j < desagendadas.size();) {
            if (tempoAtual + desagendadas[j] <= consulta.fim) {
                tempoAtual += desagendadas[j];
                atendidos++;
                desagendadas.erase(desagendadas.begin() + j);
            } else {
                j++;
            }
        }
        tempoAtual = consulta.fim;
    }

    for (int j = 0; j < desagendadas.size();) {
        if (tempoAtual + desagendadas[j] <= 100000) {
            tempoAtual += desagendadas[j];
            atendidos++;
            desagendadas.erase(desagendadas.begin() + j);
        } else {
            j++;
        }
    }

    cout << atendidos << endl;
    return 0;
}
