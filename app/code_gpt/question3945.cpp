/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Pokemon {
    string nome;
    string tipo;
    int ataque;
    int defesa;
};

vector<Pokemon> pokemons;

void listar(string tipo) {
    int i = 1;
    for (const auto& p : pokemons) {
        if (p.tipo == tipo) {
            cout << "Pokemon " << i++ << ": " << p.nome << endl;
            cout << " Ataque: " << p.ataque << endl;
            cout << " Defesa: " << p.defesa << endl;
        }
    }
}

void luta(string lutaInfo) {
    string p1, p2;
    stringstream ss(lutaInfo);
    ss >> p1 >> p2 >> p2;
    Pokemon *pokemon1 = nullptr, *pokemon2 = nullptr;

    for (auto& p : pokemons) {
        if (p.nome == p1) pokemon1 = &p;
        if (p.nome == p2) pokemon2 = &p;
    }

    if (pokemon1 && pokemon2) {
        int dif1 = pokemon1->ataque - pokemon2->defesa;
        int dif2 = pokemon2->ataque - pokemon1->defesa;

        if (dif1 > dif2) {
            cout << pokemon1->nome << " deitou " << pokemon2->nome << " na porrada" << endl;
        } else if (dif1 < dif2) {
            cout << pokemon2->nome << " deitou " << pokemon1->nome << " na porrada" << endl;
        } else {
            cout << "parece que temos um empate" << endl;
        }
    }
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        Pokemon p;
        cin >> p.nome >> p.tipo >> p.ataque >> p.defesa;
        pokemons.push_back(p);
    }

    string comando;
    while (cin >> comando) {
        if (comando == "list") {
            string tipo;
            cin >> tipo;
            listar(tipo);
        } else if (comando == "luta") {
            string lutaInfo;
            cin.ignore();
            getline(cin, lutaInfo);
            luta(lutaInfo);
        } else if (comando == "0") {
            break;
        }
    }

    return 0;
}
