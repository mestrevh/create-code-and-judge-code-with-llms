/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string referencia(const string& nome) {
    vector<string> nomes;
    stringstream ss(nome);
    string palavra;

    while (ss >> palavra) {
        nomes.push_back(palavra);
    }

    if (nomes.empty()) return "";

    // Último nome
    string ultimoNome = nomes.back();
    nomes.pop_back();

    // Mantenha os artigos
    vector<string> artigos = {"de", "da", "do", "dos", "das", "e"};
    string resultado = "";

    // Cria a referência
    if (find(artigos.begin(), artigos.end(), ultimoNome) != artigos.end()) {
        resultado += ultimoNome + ", ";
    } else {
        transform(ultimoNome.begin(), ultimoNome.end(), ultimoNome.begin(), ::toupper);
        resultado += ultimoNome + ", ";
    }

    for (const auto& n : nomes) {
        if (find(artigos.begin(), artigos.end(), n) == artigos.end()) {
            resultado += n + " ";
        }
    }

    resultado += ".";
    return resultado;
}

int main() {
    string nome;
    getline(cin, nome);
    cout << referencia(nome) << endl;
    return 0;
}
