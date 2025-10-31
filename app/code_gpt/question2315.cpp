/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Shuriken {
    string nome;
    int tamanho;
};

bool comparacao(const Shuriken &a, const Shuriken &b) {
    return a.tamanho < b.tamanho;
}

int main() {
    int N, i;
    cin >> N;
    vector<Shuriken> shurikens(N);

    for (int j = 0; j < N; ++j) {
        cin >> shurikens[j].nome >> shurikens[j].tamanho;
        shurikens[j].tamanho = stoi(shurikens[j].tamanho);
    }

    sort(shurikens.begin(), shurikens.end(), comparacao);

    cin >> i;
    cout << "Naruto devera usar a shuriken " << shurikens[i-1].nome << " para esta maquina." << endl;

    return 0;
}
