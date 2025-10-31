/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int cav, arco, pris, cachorro;
    cin >> cav >> arco >> pris >> cachorro;

    int ataque_rapido = (cav == 0) ? 1 : 0;
    int espionar = (cav == 1 || arco == 1) ? 1 : 0;
    int sinalizar = (pris == 1 && arco == 0) ? 1 : 0;
    
    int resgatar;
    if (cachorro == 1) {
        resgatar = (arco == 0) ? 1 : 0;
    } else {
        resgatar = (pris == 1 && cav == 0 && arco == 0) ? 1 : 0;
    }

    cout << ataque_rapido << " " << espionar << " " << sinalizar << " " << resgatar << endl;

    return 0;
}
