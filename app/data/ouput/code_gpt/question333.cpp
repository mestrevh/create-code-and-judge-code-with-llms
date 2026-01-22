/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void corrigirTexto(vector<string>& textos) {
    for (string& texto : textos) {
        bool novaFrase = true;
        for (char& c : texto) {
            if (novaFrase && islower(c)) {
                c = toupper(c);
                novaFrase = false;
            }
            if (c == '.') {
                novaFrase = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> textos(n);
    
    for (int i = 0; i < n; ++i) {
        getline(cin, textos[i]);
    }
    
    corrigirTexto(textos);
    
    for (const string& texto : textos) {
        cout << texto << endl;
    }

    return 0;
}
