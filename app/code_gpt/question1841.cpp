/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main() {
    string jogador;
    int pontos;
    map<string, int> jogadores;
    
    while (true) {
        getline(cin, jogador);
        if (jogador == "sair") break;
        cin >> pontos;
        cin.ignore(); // Para descartar o '\n' após a entrada de pontos
        jogadores[jogador] = pontos;
    }
    
    if (jogadores.empty()) {
        cout << "Nenhum jogador foi registrado." << endl;
        return 0;
    }
    
    string menor, maior;
    int minPontos = INT_MAX, maxPontos = INT_MIN;
    double soma = 0;
    
    for (const auto& [nome, pontuacao] : jogadores) {
        soma += pontuacao;
        if (pontuacao < minPontos) {
            minPontos = pontuacao;
            menor = nome;
        }
        if (pontuacao >= maxPontos) { // Usa >= para considerar o último em caso de empate
            maxPontos = pontuacao;
            maior = nome;
        }
    }
    
    cout << menor << endl;
    cout << maior << endl;
    cout << fixed << setprecision(2) << soma / jogadores.size() << endl;

    return 0;
}
