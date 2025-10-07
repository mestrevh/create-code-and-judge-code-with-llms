/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string nome1, nome2;
    int e1, e2;
    string c1, c2;
    float p1, p2;

    getline(cin, nome1);
    getline(cin, nome2);
    cin >> e1 >> e2;
    cin >> c1 >> c2;
    cin >> p1 >> p2;

    if (e1 > e2) {
        cout << "O hotel " << nome1 << " e a melhor opcao de estadia!" << endl;
    } else if (e2 > e1) {
        cout << "O hotel " << nome2 << " e a melhor opcao de estadia!" << endl;
    } else {
        if (c1 == "Sim" && c2 == "Nao") {
            cout << "O hotel " << nome1 << " e a melhor opcao de estadia!" << endl;
        } else if (c2 == "Sim" && c1 == "Nao") {
            cout << "O hotel " << nome2 << " e a melhor opcao de estadia!" << endl;
        } else {
            if (p1 < p2) {
                cout << "O hotel " << nome1 << " e a melhor opcao de estadia!" << endl;
            } else if (p2 < p1) {
                cout << "O hotel " << nome2 << " e a melhor opcao de estadia!" << endl;
            } else {
                cout << "Ambos os hoteis sao boas opcoes de estadia!" << endl;
            }
        }
    }

    return 0;
}
