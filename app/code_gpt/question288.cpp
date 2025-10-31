/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int ig, ai, encap, indent, str;
    cin >> ig >> ai >> encap >> indent >> str;

    if ((ig || ai) && encap && indent && str) {
        cout << "AVALIADO\n";
    } else {
        cout << "0\n";
    }

    return 0;
}
