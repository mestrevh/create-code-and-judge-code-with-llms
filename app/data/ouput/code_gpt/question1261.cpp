/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    map<string, int> vitorias;
    string casas[] = {"Gryffindor", "Slytherin", "Hufflepuff", "Ravenclaw"};
    for (const auto& casa : casas) vitorias[casa] = 0;

    for (int i = 0; i < N; ++i) {
        string confronto, placar;
        getline(cin, confronto);
        getline(cin, placar);
        
        string C1 = confronto.substr(0, confronto.find('x'));
        string C2 = confronto.substr(confronto.find('x') + 1);
        
        int P1 = stoi(placar.substr(0, placar.find('-')));
        int P2 = stoi(placar.substr(placar.find('-') + 1));

        if (P1 > P2) vitorias[C1]++;
        else if (P2 > P1) vitorias[C2]++;
    }

    int max_vitorias = 0;
    for (const auto& casa : casas) {
        max_vitorias = max(max_vitorias, vitorias[casa]);
    }

    for (const auto& casa : casas) {
        if (vitorias[casa] == max_vitorias) {
            cout << casa << endl;
        }
    }

    return 0;
}
