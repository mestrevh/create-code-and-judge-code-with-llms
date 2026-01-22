/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    char x;
    cin >> x;

    if (isalpha(x)) {
        x = tolower(x);
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            cout << "A letra " << x << " eh uma vogal" << endl;
        } else {
            cout << "A letra " << x << " eh uma consoante" << endl;
        }
    } else {
        cout << "O caractere " << x << " nao eh nem consoante nem vogal" << endl;
    }

    return 0;
}
