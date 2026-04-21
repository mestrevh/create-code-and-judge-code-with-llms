/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2;
    string sex;
    int inscritos = 0;
    int aprovados = 0;
    int mulheresAprovadas = 0;
    int homensAprovados = 0;

    while (cin >> n1) {
        if (n1 < 0) break;

        while (n1 > 100) {
            cout << "Digite uma nota inferior a 100." << endl;
            if (!(cin >> n1)) goto print_results;
            if (n1 < 0) goto print_results;
        }

        if (!(cin >> n2)) break;
        while (n2 > 100) {
            cout << "Digite uma nota inferior a 100." << endl;
            if (!(cin >> n2)) goto print_results;
        }

        if (!(cin >> sex)) break;

        inscritos++;

        if (n1 > 40 && n2 > 40 && (n1 + n2) >= 120) {
            aprovados++;
            if (sex == "F") {
                mulheresAprovadas++;
            } else if (sex == "M") {
                homensAprovados++;
            }
        }
    }

print_results:
    cout << inscritos << " candidato(s) inscrito(s)." << "\n";
    cout << aprovados << " candidato(s) aprovado(s)." << "\n";
    cout << mulheresAprovadas << " mulher(es) e " << homensAprovados << " homem(ns)." << "\n";

    return 0;
}