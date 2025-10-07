/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>

struct Acao {
    std::string codigo;
    std::string descricao;
    double valorCompra;
    int quantidade;
    std::vector<double> historico;

    void adicionaHistorico(double valor) {
        if (historico.size() >= 10) {
            historico.erase(historico.begin());
        }
        historico.push_back(valor);
    }

    double calculaMedia() {
        double soma = 0.0;
        for (double valor : historico) {
            soma += valor;
        }
        return historico.empty() ? 0.0 : soma / historico.size();
    }
};

int main() {
    std::map<std::string, Acao> acoes;
    std::string codigo;
    
    while (true) {
        std::getline(std::cin, codigo);
        if (codigo == "fim") break;

        Acao acao;
        acao.codigo = codigo;

        std::getline(std::cin, acao.descricao);
        std::cin >> acao.valorCompra;
        std::cin >> acao.quantidade;
        std::cin.ignore(); // Limpar o buffer

        acoes[codigo] = acao;
    }

    while (true) {
        std::getline(std::cin, codigo);
        if (codigo == "fim") break;

        double valorAtual;
        std::cin >> valorAtual;
        std::cin.ignore(); // Limpar o buffer

        if (acoes.find(codigo) == acoes.end()) {
            std::cout << "Acao nao registrada" << std::endl;
            continue;
        }

        Acao &acao = acoes[codigo];
        acao.adicionaHistorico(valorAtual);

        double media = acao.calculaMedia();
        double valorAnterior = acao.historico.size() > 1 ? acao.historico[acao.historico.size() - 2] : 0.0;

        if (valorAtual > media || valorAtual > valorAnterior) {
            std::cout << "Venda" << std::endl;
        } else {
            std::cout << "Compra" << std::endl;
        }
    }

    return 0;
}
