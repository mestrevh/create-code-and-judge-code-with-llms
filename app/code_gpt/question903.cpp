/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> gabarito = {'A', 'B', 'C', 'D', 'E', 'E', 'D', 'C', 'B', 'A'};
    char resposta;
    int nota = 0;

    for (int i = 0; i < 10; ++i) {
        cout << "Insira a resposta do aluno para a pergunta " << i + 1 << ":" << endl;
        cin >> resposta;
        if (resposta == gabarito[i]) {
            nota++;
        }
    }

    cout << "Nota do aluno: " << nota << endl;
    return 0;
}
