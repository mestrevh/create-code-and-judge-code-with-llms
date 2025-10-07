/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string nome, tipo;
    int poder;
    vector<string> nomes;
    vector<string> tipos;
    vector<int> poderes;

    while (cin >> nome >> tipo >> poder) {
        nomes.push_back(nome);
        tipos.push_back(tipo);
        poderes.push_back(poder);
    }

    int poder_total = 0;
    for (int p : poderes) {
        poder_total += p;
    }

    map<string, int> contagem_tipos;
    for (string t : tipos) {
        contagem_tipos[t]++;
    }

    string tipo_resultante = "";
    int max_contagem = 0;
    for (auto const& [tipo, contagem] : contagem_tipos) {
        if (contagem > max_contagem) {
            max_contagem = contagem;
            tipo_resultante = tipo;
        } else if (contagem == max_contagem) {
            vector<string> ordem = {"fogo", "agua", "planta", "eletrico", "dragao"};
            if (find(ordem.begin(), ordem.end(), tipo) < find(ordem.begin(), ordem.end(), tipo_resultante)) {
                tipo_resultante = tipo;
            }
        }
    }

    int max_nome = 0;
    for (string n : nomes) {
        if (n.length() > max_nome) {
            max_nome = n.length();
        }
    }

    string nome_resultante = "";
    int deslocamento = 0;
    for (int i = 0; i < nomes.size(); i++) {
        double fracao = (double)poderes[i] / poder_total;
        int contribuicao = max(1, (int)floor(fracao * max_nome));
        for (int j = 0; j < contribuicao; j++) {
            nome_resultante += nomes[i][(deslocamento + j) % nomes[i].length()];
        }
        deslocamento += contribuicao;
    }

    cout << "Nome: " << nome_resultante << endl;
    cout << "Tipo: " << tipo_resultante << endl;
    cout << "Poder: " << poder_total << endl;

    return 0;
}
