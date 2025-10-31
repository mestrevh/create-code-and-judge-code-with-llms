/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Sala {
    int id;
    int aprovados;
};

struct Aluno {
    std::string nome;
    float presenca;
    int notas[3][3];
};

float media(int notas[3]) {
    return (notas[0] + notas[1] + notas[2]) / 3.0;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Sala> salas;
    
    for (int i = 0; i < n; i++) {
        int id, q;
        std::cin >> id >> q;
        Sala sala = {id, 0};
        
        for (int j = 0; j < q; j++) {
            Aluno aluno;
            std::cin >> aluno.nome >> aluno.presenca;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    std::cin >> aluno.notas[k][l];
                }
            }
            
            float mediaMat = media(aluno.notas[0]);
            float mediaPort = media(aluno.notas[1]);
            float mediaHist = media(aluno.notas[2]);
            
            if (mediaMat >= 7 && mediaPort >= 7 && mediaHist >= 7 && aluno.presenca >= 0.75) {
                sala.aprovados++;
            }
        }
        
        salas.push_back(sala);
    }

    std::stable_sort(salas.begin(), salas.end(), [](const Sala &a, const Sala &b) {
        return a.aprovados > b.aprovados;
    });

    for (size_t i = 0; i < salas.size(); i++) {
        std::cout << i + 1 << ". [SALA #" << salas[i].id << "] APROVADOS: " << salas[i].aprovados << std::endl;
    }

    return 0;
}
