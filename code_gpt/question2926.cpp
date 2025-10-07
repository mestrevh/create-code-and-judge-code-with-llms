/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    unordered_map<string, vector<string>> presentes;
    string linha;

    while (getline(cin, linha) && linha != "FIM") {
        int X = stoi(linha);
        for (int i = 0; i < X; ++i) {
            getline(cin, linha);
            stringstream ss(linha);
            string nome, presente;
            ss >> nome;
            while (ss >> presente) {
                presentes[nome].push_back(presente);
            }
        }

        while (getline(cin, linha) && linha != "FIM") {
            stringstream ss(linha);
            string nome, presente;
            ss >> nome >> presente;
            if (presentes[nome].end() != find(presentes[nome].begin(), presentes[nome].end(), presente)) {
                cout << "Uhul! Seu amigo secreto vai adorar\n";
            } else {
                cout << "Tente Novamente!\n";
            }
        }
    }
    return 0;
}
