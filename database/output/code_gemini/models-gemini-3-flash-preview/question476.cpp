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

    int X;
    if (!(cin >> X)) return 0;
    
    string dummy;
    getline(cin, dummy); 

    while (X--) {
        string name;
        while (getline(cin, name) && name.empty());
        
        int id, level, vida, ataque, defesa;
        if (!(cin >> id >> level >> vida >> ataque >> defesa)) break;
        getline(cin, dummy);

        cout << "Nome: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Level: " << level << "\n";
        cout << "Vida: " << vida << "\n";
        cout << "Ataque: " << ataque << "\n";
        cout << "Defesa: " << defesa << "\n";
    }

    return 0;
}