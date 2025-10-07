/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Ninja {
    string nome;
    int chakra;
    int jutsus;
    int potencial;
};

bool comparator(const Ninja &a, const Ninja &b) {
    return a.potencial > b.potencial;
}

int main() {
    string status;
    cin >> ws;
    getline(cin, status);
    int n;
    cin >> n;
    vector<Ninja> ninjas(n);

    for (int i = 0; i < n; i++) {
        cin >> ninjas[i].nome >> ninjas[i].chakra >> ninjas[i].jutsus;
        ninjas[i].potencial = ninjas[i].chakra - ninjas[i].jutsus;
    }

    if (status == "Esse naruto...") {
        reverse(ninjas.begin(), ninjas.end());
    }

    sort(ninjas.begin(), ninjas.end(), comparator);

    int classificados = 0;
    for (const auto &ninja : ninjas) {
        if (ninja.potencial > 0) {
            cout << ninja.nome << " esta classificado(a)" << endl;
            classificados++;
        } else {
            cout << ninja.nome << " esta desclassificado(a)" << endl;
        }
    }

    cout << endl;
    if (classificados > 0) {
        cout << "Kakashi tera um total de " << classificados << " aluno(s) nesse semestre" << endl;
    } else {
        cout << "Esse semestre ninguem veio treinar na aldeia da folha" << endl;
    }

    return 0;
}
