/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Clube {
    string nome;
    int dinheiro;
    char foco;
    vector<string> jogadoresComprados;
};

struct Jogador {
    string nome;
    string pais;
    int ataque;
    int defesa;
    int custo;
};

int main() {
    int N;
    cin >> N;
    vector<Clube> clubes;
    
    for (int i = 0; i < N; ++i) {
        string nome;
        int dinheiro;
        char foco;
        cin >> nome;
        if (nome == "Vasco") {
            cout << "Vasco nao tem salvacao, tomou 3 pro vitoria em casa\n";
            continue;
        }
        cin >> dinheiro >> foco;
        clubes.push_back({nome, dinheiro, foco, {}});
    }
    
    int N2;
    cin >> N2;
    vector<Jogador> jogadores(N2);
    
    for (int i = 0; i < N2; ++i) {
        cin >> jogadores[i].nome >> jogadores[i].pais;
        cin >> jogadores[i].ataque >> jogadores[i].defesa >> jogadores[i].custo;
    }
    
    for (const auto& jogador : jogadores) {
        Clube* clubeEscolhido = nullptr;
        for (auto& clube : clubes) {
            if (clube.dinheiro >= jogador.custo) {
                if (!clubeEscolhido) {
                    clubeEscolhido = &clube;
                } else {
                    if ((jogador.ataque >= jogador.defesa && clube.foco == 'A' && clubeEscolhido->foco != 'A') ||
                        (jogador.defesa > jogador.ataque && clube.foco == 'D' && clubeEscolhido->foco != 'D') ||
                        (clube.foco == clubeEscolhido->foco && (clube.dinheiro > clubeEscolhido->dinheiro || 
                        (clube.dinheiro == clubeEscolhido->dinheiro && &clube < clubeEscolhido)))) {
                        clubeEscolhido = &clube;
                    }
                }
            }
        }
        
        if (clubeEscolhido) {
            cout << jogador.nome << " eh do " << clubeEscolhido->nome << endl;
            clubeEscolhido->dinheiro -= jogador.custo;
            clubeEscolhido->jogadoresComprados.push_back(jogador.nome + " " + jogador.pais);
        } else {
            cout << jogador.nome << " ta muito caro\n";
        }
    }

    for (const auto& clube : clubes) {
        cout << "Situacao " << clube.nome << endl;
        cout << "Dinheiro restante = " << clube.dinheiro << endl;
        cout << "Num de Jogadores = " << clube.jogadoresComprados.size() << endl;
        for (const auto& j : clube.jogadoresComprados) {
            cout << j << endl;
        }
        cout << endl;
    }
    
    return 0;
}
