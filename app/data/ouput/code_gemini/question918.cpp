/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    int channel;
    cin >> channel;
    cout << "Digite um numero de um canal de tv:" << endl;
    switch (channel) {
        case 2:
            cout << "SBT" << endl;
            break;
        case 4:
            cout << "BAND" << endl;
            break;
        case 6:
            cout << "REDETV!" << endl;
            break;
        case 9:
            cout << "RECORD" << endl;
            break;
        case 13:
            cout << "GLOBO" << endl;
            break;
        default:
            cout << "Canal Invalido" << endl;
            break;
    }
    return 0;
}
