/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            int age, friends, photos;
            string name;
            char sex, status;

            if (!(cin >> age)) break;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (!getline(cin, name)) break;
            
            if (!(cin >> sex >> status >> friends >> photos)) break;

            cout << "Idade: " << age << "\n";
            cout << "Nome: " << name << "\n";
            cout << "Sexo: " << sex << "\n";
            cout << "Estado Civil: " << status << "\n";
            cout << "Numero de amigos: " << friends << "\n";
            cout << "Numero de fotos: " << photos << "\n\n";
        }
    }

    return 0;
}