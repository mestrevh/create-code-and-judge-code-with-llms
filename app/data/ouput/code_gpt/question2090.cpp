/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    unordered_map<string, int> anoes;
    vector<string> ordem;
    int comidaTotal = 0;

    for (int i = 0; i < n; ++i) {
        string comando;
        getline(cin, comando);
        
        if (comando.find("ENTROU:") != string::npos) {
            string nome = comando.substr(8);
            if (anoes.find(nome) == anoes.end()) {
                int quantidade;
                cin >> quantidade;
                cin.ignore();
                anoes[nome] = quantidade;
                ordem.push_back(nome);
                comidaTotal += quantidade;
                cout << nome << " entrou e gostaria de " << quantidade << "g de comida." << endl;
            } else {
                cout << nome << " ja estava em casa." << endl;
            }
        } else if (comando.find("SAIU:") != string::npos) {
            string nome = comando.substr(6);
            if (anoes.find(nome) != anoes.end()) {
                comidaTotal -= anoes[nome];
                anoes.erase(nome);
                cout << nome << " saiu de casa." << endl;
            } else {
                cout << nome << " nao estava na casa." << endl;
            }
        }
    }

    if (anoes.size() == 7) {
        cout << "teoria da branca de neve: porque só ter um se eu posso ter sete." << endl;
    } else {
        cout << "Estao na casa " << anoes.size() << " anoes:" << endl;
        for (const auto& nome : ordem) {
            if (anoes.find(nome) != anoes.end()) {
                cout << nome << endl;
            }
        }
        cout << comidaTotal << endl;
    }
    
    return 0;
}
