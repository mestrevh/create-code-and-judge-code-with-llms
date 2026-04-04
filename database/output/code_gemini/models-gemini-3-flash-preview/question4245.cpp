/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

struct Caixa {
    long long largura;
    long long profundidade;
    long long altura;

    long long volume() const {
        return largura * profundidade * altura;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    bool encontrou = false;
    for (int i = 0; i < n; ++i) {
        Caixa c;
        cin >> c.largura >> c.profundidade >> c.altura;
        
        if (c.altura <= 10) {
            cout << c.volume() << "\n";
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "Nenhuma caixa passa pelo tunel!" << endl;
    }

    return 0;
}