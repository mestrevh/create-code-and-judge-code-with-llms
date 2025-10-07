/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

struct Pokemon {
    string nome;
    string tipo;
    int poder;
};

int main() {
    vector<Pokemon> pokemons;
    string nome, tipo;
    int poder;

    while (getline(cin, nome)) {
        getline(cin, tipo);
        cin >> poder;
        cin.ignore();
        pokemons.push_back({nome, tipo, poder});
    }

    map<string, int> tipo_freq;
    int total_poder = 0;
    int max_nome_length = 0;

    for (const auto& p : pokemons) {
        tipo_freq[p.tipo]++;
        total_poder += p.poder;
        if (p.nome.length() > max_nome_length) {
            max_nome_length = p.nome.length();
        }
    }

    string tipo_resultante;
    int max_freq = 0;
    vector<string> tipos = {"fogo", "agua", "planta", "eletrico", "dragao"};
    
    for (const auto& tipo : tipos) {
        if (tipo_freq[tipo] > max_freq) {
            max_freq = tipo_freq[tipo];
            tipo_resultante = tipo;
        }
    }

    string nome_resultante;
    int index = 0;

    for (const auto& p : pokemons) {
        double fraction = static_cast<double>(p.poder) / total_poder;
        int contribution = static_cast<int>(floor(fraction * max_nome_length));
        if (contribution == 0) contribution = 1;

        for (int i = 0; i < contribution; i++) {
            if (index < p.nome.length()) {
                nome_resultante += p.nome[index];
            } else {
                nome_resultante += p.nome[p.nome.length() - 1];
            }
            index++;
        }
    }

    cout << "Nome: " << nome_resultante << endl;
    cout << "Tipo: " << tipo_resultante << endl;
    cout << "Poder: " << total_poder << endl;

    return 0;
}
