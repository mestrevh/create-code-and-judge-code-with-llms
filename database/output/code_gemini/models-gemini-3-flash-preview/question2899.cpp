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

    double height;
    int age;
    string sex;

    while (true) {
        cout << "Digite a altura do entrevistado:\n";
        if (!(cin >> height) || height == 0) {
            break;
        }
        cout << "Digite a idade do entrevistado:\n";
        if (!(cin >> age)) break;
        cout << "Digite o sexo do entrevistado (M ou F):\n";
        if (!(cin >> sex)) break;
    }

    return 0;
}