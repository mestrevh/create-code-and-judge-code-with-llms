/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int age;
    while (cin >> age && age != 0) {
        if (age < 0) {
            cout << "Você ainda não nasceu." << "\n";
        } else if (age < 16) {
            cout << "Você não pode votar." << "\n";
        } else if (age >= 18 && age <= 70) {
            cout << "Você tem a obrigatoriedade de votar." << "\n";
        } else {
            cout << "Na sua idade, o voto é opcional." << "\n";
        }
    }

    return 0;
}