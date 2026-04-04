/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

/**
 * Problema: Compras de Fim de Ano
 * Estratégia: Utilizar um map (dicionário) para armazenar os produtos e seus preços,
 * permitindo busca e remoção eficiente por nome. O parsing é feito considerando
 * que o preço é sempre o último termo da linha na entrada inicial.
 */

int main() {
    // Otimização de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, double> products;
    string line;

    // Fase 1: Leitura da lista de produtos e seus preços
    while (getline(cin, line)) {
        // Remover espaços em branco ou caracteres de quebra de linha à direita (\r, \n)
        while (!line.empty() && isspace((unsigned char)line.back())) {
            line.pop_back();
        }
        
        // Finaliza a entrada de produtos ao encontrar '*'
        if (line == "*") break;
        if (line.empty()) continue;

        // O nome pode conter espaços, mas o preço é o último valor numérico
        // Encontramos o último espaço para separar o nome do preço
        size_t last_space = line.find_last_of(' ');
        if (last_space != string::npos) {
            string name = line.substr(0, last_space);
            string price_str = line.substr(last_space + 1);
            try {
                // Armazena no dicionário; nomes repetidos são sobrescritos (comportamento de dicionário)
                products[name] = stod(price_str);
            } catch (...) {
                // Em competições, assume-se que a entrada segue o formato estrito
            }
        }
    }

    // Fase 2: Processamento de comandos (retire, quantidade, total)
    string cmd;
    while (cin >> cmd) {
        if (cmd == "retire") {
            string name;
            // Ignorar espaços iniciais logo após o comando "retire" para ler o nome completo
            while (cin.peek() == ' ') cin.ignore();
            getline(cin, name);
            
            // Remover eventuais quebras de linha ou espaços residuais à direita
            while (!name.empty() && isspace((unsigned char)name.back())) {
                name.pop_back();
            }
            
            // Remove o item da lista se ele existir
            products.erase(name);
        } else if (cmd == "quantidade") {
            // Imprime o número atual de itens únicos na lista
            cout << products.size() << "\n";
        } else if (cmd == "total") {
            // Calcula a soma de todos os preços no dicionário
            double total_sum = 0.0;
            for (auto const& [name, price] : products) {
                total_sum += price;
            }
            // Saída formatada com duas casas decimais
            cout << fixed << setprecision(2) << total_sum << "\n";
            break; // Comando total encerra o programa
        }
    }

    return 0;
}