/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

/**
 * Função para converter uma string para letras maiúsculas.
 * Útil para lidar com sentinelas "fim" de forma robusta.
 */
string toUpper(string s) {
    for (char &c : s) {
        c = (char)toupper((unsigned char)c);
    }
    return s;
}

int main() {
    // Otimização de I/O padrão para C++ em maratonas de programação
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Mapeamento do Código da Ação para seu histórico de valores
    map<string, vector<double>> stocks;
    string code;

    // PARTE 1: Cadastro das ações
    while (cin >> code) {
        if (toUpper(code) == "FIM") break;
        
        // Ignora o restante da linha do código para ler a descrição com getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        string description;
        if (!getline(cin, description)) break;
        
        double purchase_price;
        int quantity;
        if (!(cin >> purchase_price >> quantity)) break;
        
        // Inicializa o histórico com o valor de compra fornecido no cadastro
        stocks[code].push_back(purchase_price);
    }

    // PARTE 2: Processamento das decisões de compra/venda
    while (cin >> code) {
        if (toUpper(code) == "FIM") break;
        
        double current_price;
        if (!(cin >> current_price)) break;
        
        // Verifica se a ação está cadastrada no mapa
        auto it = stocks.find(code);
        if (it != stocks.end()) {
            vector<double> &hist = it->second;
            
            // O valor anterior é o último elemento do histórico antes da atualização
            double previous = hist.back();
            
            // Adiciona o valor atual ao histórico
            hist.push_back(current_price);
            
            // Mantém apenas os últimos 10 valores no histórico (conforme restrição)
            if (hist.size() > 10) {
                hist.erase(hist.begin());
            }
            
            // Cálculo da média do histórico atualizado
            double sum = 0;
            for (double p : hist) {
                sum += p;
            }
            double avg = sum / (double)hist.size();
            
            // REGRAS DE DECISÃO:
            // 1. Valor atual > média do histórico OU
            // 2. Valor atual > valor anterior
            // Se qualquer uma for verdadeira, sugere-se VENDA. Caso contrário, COMPRA.
            if (current_price > avg || current_price > previous) {
                cout << "Venda\n";
            } else {
                cout << "Compra\n";
            }
        }
    }

    return 0;
}