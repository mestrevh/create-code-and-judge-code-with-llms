/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

void distribuirDinheiro(const string& atual, const unordered_map<string, string>& relacoes, unordered_set<string>& jaReceberam, vector<string>& resultado) {
    if (jaReceberam.count(atual)) return;
    jaReceberam.insert(atual);
    resultado.push_back(atual);
    distribuirDinheiro(relacoes.at(atual), relacoes, jaReceberam, resultado);
}

int main() {
    int N;
    cin >> N;
    unordered_map<string, string> relacoes;
    for (int i = 0; i < N; ++i) {
        string nome, destino;
        cin >> nome >> destino;
        relacoes[nome] = destino;
    }
    string inicial;
    cin >> inicial;
    unordered_set<string> jaReceberam;
    vector<string> resultado;
    distribuirDinheiro(inicial, relacoes, jaReceberam, resultado);
    for (const auto& nome : resultado) {
        cout << nome << " ";
    }
    cout << endl;
    return 0;
}
