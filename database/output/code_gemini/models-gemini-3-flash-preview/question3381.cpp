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

    if (age <= 2) {
        cout << "O individuo eh um Bebe Jovem Menor de Idade.\n";
    } else if (age <= 12) {
        cout << "O individuo eh uma Crianca Jovem Menor de Idade.\n";
    } else if (age <= 18) {
        cout << "O individuo eh um Adolescente Jovem Menor de Idade.\n";
    } else if (age <= 19) {
        cout << "O individuo eh um Jovem Maior de Idade.\n";
    } else if (age <= 45) {
        cout << "O individuo eh um Adulto Maior de Idade.\n";
    } else if (age <= 60) {
        cout << "O individuo eh um Adulto de Meia Idade Maior de Idade.\n";
    } else if (age <= 74) {
        cout << "O individuo eh um Idoso Maior de Idade.\n";
    } else if (age <= 90) {
        cout << "O individuo eh um Idoso Ansiao Maior de Idade.\n";
    } else {
        cout << "O individuo eh um Idoso na Velhice Extrema Maior de Idade.\n";
    }

    return 0;
}