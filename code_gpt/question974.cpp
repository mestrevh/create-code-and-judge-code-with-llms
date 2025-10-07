/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

struct Carta {
    int dia, ano;
    string mes, remetente, destinatario;

    bool operator<(const Carta& other) const {
        if (ano != other.ano) return ano < other.ano;
        if (mes != other.mes) return mes < other.mes;
        return dia < other.dia;
    }
};

int getMesNumero(const string& mes) {
    map<string, int> meses = {
        {"janeiro", 1}, {"fevereiro", 2}, {"março", 3},
        {"abril", 4}, {"maio", 5}, {"junho", 6},
        {"julho", 7}, {"agosto", 8}, {"setembro", 9},
        {"outubro", 10}, {"novembro", 11}, {"dezembro", 12}
    };
    return meses[mes];
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    vector<Carta> cartas;

    for (int i = 0; i < N; ++i) {
        Carta c;
        string data;
        getline(cin, data);
        stringstream ss(data);
        ss >> c.dia;
        ss >> c.mes;
        ss >> c.mes; // para pegar "de"
        ss >> c.ano;
        getline(cin, c.remetente);
        getline(cin, c.destinatario);
        c.mes = c.mes == "Abril" ? "abril" : c.mes; // normalizar mês
        cartas.push_back(c);
    }

    sort(cartas.begin(), cartas.end());

    for (const auto& c : cartas) {
        cout << c.dia << " de " << c.mes << " de " << c.ano << endl;
        cout << c.remetente << endl;
        cout << c.destinatario << endl;
    }

    return 0;
}
