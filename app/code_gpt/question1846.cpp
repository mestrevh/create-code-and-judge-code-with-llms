/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome;
    getline(cin, nome);
    for (size_t i = 1; i <= nome.length(); ++i) {
        cout << nome.substr(0, i) << endl;
    }
    return 0;
}
