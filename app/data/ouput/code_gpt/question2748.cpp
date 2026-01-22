/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int Fd, Bd, Md, Fr, Br, Mr;
    cin >> Fd >> Bd >> Md;
    cin >> Fr >> Br >> Mr;

    int naoAtendidos = 0;
    naoAtendidos += max(0, Fr - Fd);
    naoAtendidos += max(0, Br - Bd);
    naoAtendidos += max(0, Mr - Md);
    
    cout << naoAtendidos << endl;
    return 0;
}
