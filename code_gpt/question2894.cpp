/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int hp, x;
    cin >> hp >> x;
    cin.ignore();
    
    string acerto;
    for (int i = 0; i < x; i++) {
        getline(cin, acerto);
        if (acerto == "nuca") {
            continue;
        } else if (acerto == "cabeca") {
            hp -= 30;
        } else {
            hp -= 50;
        }
    }

    if (hp > 0) {
        if (x > 0) {
            cout << "Levi sobreviveu com " << hp << " de HP e sobraram " << x << " inimigos" << endl;
        } else {
            cout << "Levi sobreviveu com " << hp << " de HP e nao sobraram inimigos" << endl;
        }
    } else {
        cout << "Infelizmente o Levi nao sobreviveu..." << endl;
    }

    return 0;
}
