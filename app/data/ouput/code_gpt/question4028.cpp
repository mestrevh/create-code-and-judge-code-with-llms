/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int num;
    cin >> num;

    if (num <= 100) return 0;

    vector<string> notas = {"do", "re", "mi", "fa", "sol", "la", "si"};
    int tonica = (num / 100) % 7;
    int terça = (num / 10) % 7;
    int quinta = num % 7;

    if ((tonica == 0 && terça == 2 && quinta == 4) || 
        (tonica == 1 && terça == 3 && quinta == 5) || 
        (tonica == 2 && terça == 4 && quinta == 6) || 
        (tonica == 3 && terça == 5 && quinta == 0) || 
        (tonica == 4 && terça == 6 && quinta == 1) || 
        (tonica == 5 && terça == 0 && quinta == 2) || 
        (tonica == 6 && terça == 1 &&quinta == 3)) {
        cout << "Acorde " << notas[tonica] << " satisfaz." << endl;
    } else {
        cout << "Combinacao nao satisfaz." << endl;
    }

    return 0;
}
