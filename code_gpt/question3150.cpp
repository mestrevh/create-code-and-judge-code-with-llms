/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, B, C, energia;
    char arma;
    cin >> A >> B >> C >> energia >> arma;

    int dano = (arma == 'C') ? 40 : 50;
    int custo = (arma == 'C') ? 15 : 20;
    int inimigos[] = {A, B, C};

    for (int i = 0; i < 3; i++) {
        while (inimigos[i] > 0 && energia > 0) {
            inimigos[i] -= dano;
            energia -= custo;

            if (energia < (energia*0.3)) {
                custo *= 2;
            }
        }
        if (energia <= 0) break;
    }

    if (energia > 0) {
        cout << "Eba! Pedro sobreviveu" << endl;
    } else {
        cout << "Que pena... Era um jovem tao promissor" << endl;
    }

    return 0;
}
