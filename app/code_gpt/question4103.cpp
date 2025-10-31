/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X;
    cin >> N;
    vector<int> matriculas;

    for (int i = 0; i < N; ++i) {
        int codigo;
        cin >> codigo;
        if (codigo == -1) break;
        matriculas.push_back(codigo);
    }
    
    cin >> X;
    cout << matriculas[X - 1] << endl;

    return 0;
}
