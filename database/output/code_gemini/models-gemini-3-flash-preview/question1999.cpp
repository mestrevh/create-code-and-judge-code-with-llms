/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string line;
    getline(cin, line); // Consome o restante da linha após ler n

    vector<string> gab;
    if (getline(cin, line)) {
        if (line == "sair") return 0;
        stringstream ss(line);
        string t;
        while (ss >> t) {
            gab.push_back(t);
        }
    }

    // Caso o gabarito fornecido seja menor que o tamanho N solicitado
    if ((int)gab.size() < n) {
        cout << "Tamanho incorreto" << endl;
    }

    while (getline(cin, line)) {
        if (line.empty()) continue;
        
        // Verifica se a linha inteira é o comando de saída
        if (line == "sair") break;

        stringstream ss(line);
        string t;
        vector<string> user;
        while (ss >> t) {
            user.push_back(t);
        }

        // Se o usuário digitar "sair" como a primeira resposta
        if (!user.empty() && user[0] == "sair") break;
        if (user.empty()) continue;

        // Se o tamanho da resposta for diferente do gabarito esperado (n)
        if ((int)user.size() != n) {
            cout << "Tamanho incorreto" << endl;
        } else {
            int hits = 0;
            // Compara as respostas, limitando ao tamanho real do gabarito lido
            for (int i = 0; i < n; ++i) {
                if (i < (int)gab.size() && user[i] == gab[i]) {
                    hits++;
                }
            }
            
            double percentual = (n == 0) ? 0.0 : (double)hits * 100.0 / n;
            cout << "Percentual de acertos: " << fixed << setprecision(1) << percentual << endl;
        }
    }

    return 0;
}