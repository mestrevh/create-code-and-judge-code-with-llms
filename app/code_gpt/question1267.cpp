/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    vector<string> grifinoria, sonserina, corvinal, lufalufa;
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        size_t space_pos = line.find(' ');
        string name = line.substr(0, space_pos);
        string characteristic = line.substr(space_pos + 1);

        if (characteristic == "coragem" || characteristic == "determinacao") {
            grifinoria.push_back(name);
        } else if (characteristic == "astucia" || characteristic == "ambicao") {
            sonserina.push_back(name);
        } else if (characteristic == "inteligencia" || characteristic == "forca de vontade") {
            corvinal.push_back(name);
        } else if (characteristic == "lealdade" || characteristic == "companheirismo") {
            lufalufa.push_back(name);
        }
    }

    cout << "Grifinoria:\n";
    for (const string& name : grifinoria) cout << name << '\n';
    
    cout << "Sonserina:\n";
    for (const string& name : sonserina) cout << name << '\n';
    
    cout << "Corvinal:\n";
    for (const string& name : corvinal) cout << name << '\n';
    
    cout << "Lufa-lufa:\n";
    for (const string& name : lufalufa) cout << name << '\n';

    return 0;
}
