/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    unordered_map<string, int> anoes;
    vector<string> ordem;
    
    for (int i = 0; i < n; i++) {
        string comando;
        getline(cin, comando);
        
        string op = comando.substr(0, comando.find(':'));
        string nome = comando.substr(comando.find(':') + 1);
        
        if (op == "ENTROU") {
            if (anoes.find(nome) != anoes.end()) {
                cout << "Anao ja estava em casa." << endl;
            } else {
                int quantidade;
                cin >> quantidade;
                cin.ignore();
                
                anoes[nome] = quantidade;
                ordem.push_back(nome);
                cout << nome << " entrou e gostaria de " << quantidade << "g de comida." << endl;
            }
        } else if (op == "SAIU") {
            if (anoes.find(nome) == anoes.end()) {
                cout << nome << " nao estava na casa." << endl;
            } else {
                anoes.erase(nome);
                cout << nome << " saiu de casa." << endl;
            }
        }
    }
    
    cout << endl;

    int totalAnoes = anoes.size();
    int totalComida = 0;
    
    for (auto& a : anoes) {
        totalComida += a.second;
    }

    if (totalAnoes == 7) {
        cout << "teoria da branca de neve: porque so ter um se eu posso ter sete?" << endl;
    } else {
        cout << "Estao na casa " << totalAnoes << " anoes:" << endl;
        for (const auto& nome : ordem) {
            if (anoes.find(nome) != anoes.end()) {
                cout << nome << endl;
            }
        }
        cout << totalComida << endl;
    }
    
    return 0;
}
