/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int tempo;
    cin >> tempo;

    if (tempo < 0) {
        cout << "Meme man quebrou o tempo! De volta ao transito :(" << endl;
    } else if (tempo < 62) {
        cout << "...Ainda no transito..." << endl;
    } else if (tempo >= 62 && tempo < 127) { // 62 <= tempo < 127 significa 5 de Junho de 2017
        cout << "Lar doce lar" << endl;
    } else if (tempo >= 127) {
        cout << "Stonks has been born!" << endl;
    }

    return 0;
}
