/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    cin.ignore();
    vector<string> desejos(N);
    for (int i = 0; i < N; i++) {
        getline(cin, desejos[i]);
    }
    
    cin >> M;
    cin.ignore();
    unordered_set<string> feitos;
    for (int i = 0; i < M; i++) {
        string feito;
        getline(cin, feito);
        feitos.insert(feito);
    }
    
    vector<string> restantes;
    for (const string& desejo : desejos) {
        if (feitos.find(desejo) == feitos.end()) {
            restantes.push_back(desejo);
        }
    }
    
    if (restantes.empty()) {
        cout << "Smelly Cat, Smelly Cat, what are they feeding you?" << endl;
    } else {
        cout << "Ainda falta(m) " << restantes.size() << " objetivo(s)!" << endl;
        for (const string& objetivo : restantes) {
            cout << objetivo << endl;
        }
    }
    
    return 0;
}
