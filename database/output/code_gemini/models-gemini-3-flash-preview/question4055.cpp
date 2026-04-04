/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long my_hp, my_atk, rat_hp, rat_atk;
    
    if (cin >> my_hp >> my_atk >> rat_hp >> rat_atk) {
        if (my_hp * my_atk > rat_hp * rat_atk) {
            cout << "Matei um rathound" << endl;
        } else {
            cout << "Fugi de um rathound" << endl;
        }
    }

    return 0;
}