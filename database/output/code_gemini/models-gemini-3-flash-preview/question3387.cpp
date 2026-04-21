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
    if (!(cin >> age)) return 0;

    if (age >= 18) {
        cout << "Voce ja pode tirar habilitacao!" << "\n";
        cout << "Voce tem direito a habilitacao ha " << (age - 18) << " ano(s)" << "\n";
    } else {
        cout << "Voce precisa esperar mais " << (18 - age) << " ano(s)!" << "\n";
    }

    return 0;
}