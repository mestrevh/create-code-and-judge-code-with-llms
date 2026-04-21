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

    int n;
    if (!(cin >> n)) return 0;

    string firstName, lastName;
    while (n--) {
        if (!(cin >> firstName >> lastName)) break;

        cout << "Cara familia " << lastName << ", sentimos muito pela tragica morte de " << firstName << "." << "\n";

        if (lastName == "Lannister") {
            cout << "Os campos agora o ouvirao rugir." << "\n";
        } else if (lastName == "Stark") {
            cout << "O inverno chega para todos." << "\n";
        } else if (lastName == "Targaryen") {
            cout << "Voces sao superestimados mesmo." << "\n";
        }
    }

    return 0;
}