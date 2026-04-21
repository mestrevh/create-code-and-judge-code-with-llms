/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Grande Mestre em Programação Competitiva
 * Solução: Senha da Empresa Calculaí
 * Complexidade: O(N * L), onde N é o número de funcionários e L é o tamanho das strings.
 */

struct Funcionario {
    string nome_completo;
    string data_nascimento;
    string cidade_natal;
    int idade;
};

int main() {
    // Otimização de I/O padrão Maratona de Programação
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; ++i) {
        Funcionario f;
        
        // Leitura do Nome Completo e checagem da condição de saída
        if (!getline(cin, f.nome_completo) || f.nome_completo == "SAIR") {
            break;
        }
        
        // Leitura dos demais campos
        if (!getline(cin, f.data_nascimento)) break;
        if (!getline(cin, f.cidade_natal)) break;
        if (!(cin >> f.idade)) break;
        
        // Consumir a quebra de linha após a idade para o próximo getline
        string dummy;
        getline(cin, dummy);

        // Processamento da Cidade Natal para ignorar espaços (conforme observado nos casos de teste)
        string clean_city = "";
        for (char c : f.cidade_natal) {
            if (c != ' ') {
                clean_city += c;
            }
        }

        /**
         * Lógica de formação da senha (concatenação alternada):
         * 1. 1ª letra do Nome (N0)
         * 2. 1º número da Data (D0)
         * 3. 1ª letra da Cidade (C0)
         * 4. 2ª letra do Nome (N1)
         * 5. 2ª número da Data (D1)
         * 6. 2ª letra da Cidade (C1)
         * 7. 3ª letra do Nome (N2)
         * 8. 3º número da Data (D3 - pulando o '/')
         * 9. 3ª letra da Cidade (C2)
         * 10. 4ª letra do Nome (N3)
         * 11. 4º número da Data (D4)
         * 12. 4ª letra da Cidade (C3)
         * 13. 5ª letra do Nome (N4)
         * 14. Idade (terminar com a idade)
         */
        string senha = "";
        // Baseado na garantia de que o primeiro nome tem 5+ letras e data formato DD/MM/YYYY
        senha += f.nome_completo[0];
        senha += f.data_nascimento[0];
        senha += clean_city[0];
        senha += f.nome_completo[1];
        senha += f.data_nascimento[1];
        senha += clean_city[1];
        senha += f.nome_completo[2];
        senha += f.data_nascimento[3];
        senha += clean_city[2];
        senha += f.nome_completo[3];
        senha += f.data_nascimento[4];
        senha += clean_city[3];
        senha += f.nome_completo[4];
        senha += to_string(f.idade);

        // Saída formatada conforme especificações dos casos de teste
        cout << "Nome: " << f.nome_completo << "\n";
        cout << "Data de Nascimento: " << f.data_nascimento << "\n";
        cout << "Cidade Natal: " << f.cidade_natal << "\n";
        cout << "Idade: " << f.idade << " anos\n";
        cout << "Senha: " << senha << "\n\n";
    }

    return 0;
}