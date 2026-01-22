/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int alunos, total_grampos = 0;
    while (cin >> alunos) {
        total_grampos += alunos * 4;
    }
    int caixas = (total_grampos + 29) / 30;
    cout << total_grampos << endl;
    cout << caixas << endl;
    return 0;
}
