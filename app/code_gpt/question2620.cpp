/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

struct Material {
    string nome;
    int quantidade;
};

int main() {
    int N;
    cin >> N;
    Material estoque[100];

    for (int i = 0; i < N; i++) {
        cin >> estoque[i].nome >> estoque[i].quantidade;
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        string nomeRetirar;
        int qtdRetirar;
        cin >> nomeRetirar >> qtdRetirar;

        bool encontrado = false;
        for (int j = 0; j < N; j++) {
            if (estoque[j].nome == nomeRetirar) {
                encontrado = true;
                if (estoque[j].quantidade >= qtdRetirar) {
                    estoque[j].quantidade -= qtdRetirar;
                    cout << "Tem " << estoque[j].quantidade << " " << estoque[j].nome << " no estoque" << endl;
                } else {
                    cout << "Nao tem " << estoque[j].nome << " suficiente no estoque" << endl;
                }
                break;
            }
        }
    }

    return 0;
}
